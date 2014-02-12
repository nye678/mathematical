#ifndef __MATHEMATICAL_MATRIX_H_
#define __MATHEMATICAL_MATRIX_H_

#include "TemplateExpressions.h"
#include "Vector.h"

namespace mathematical {
	namespace temps {
		
		template <int N, typename T>
		class matNT {
			template <int I>
			static inline T matrixDot(matNT &lhs, const matNT &rhs, size_t row, size_t col)
			{
				return lhs[row + I * N] * rhs[col + I] + matrixDot<I - 1>(lhs, rhs, row, col);
			}

			template <>
			static inline T matrixDot<0>(matNT &lhs, const matNT &rhs, size_t row, size_t col)
			{
				return lhs[row] * rhs[col];
			}

			template <int I>
			static inline void matrixMulti(matNT &lhs, const matNT &rhs) {
				size_t row = I % N;
				size_t col = (I / N) * N;
				T dot = matrixDot<N - 1>(lhs, rhs, row, col);
				matrixMulti<I - 1>(lhs, rhs);
				lhs[I] = dot;
			}

			template <>
			static inline void matrixMulti<0>(matNT &lhs, const matNT &rhs) {
				lhs[0] = matrixDot<N - 1>(lhs, rhs, 0, 0);
			}

			typedef ArithmeticOps<T>	arith;
			typedef BooleanOps<T>		boolean;
			typedef MetaExp<matNT, T>	meta;
		protected:
			T _mat[N*N];

		public:
			matNT &operator += (const matNT &other) { meta::execute<N*N - 1>(*this, other, arith::opPlus);  return *this; }
			matNT &operator -= (const matNT &other) { meta::execute<N*N - 1>(*this, other, arith::opMinus); return *this; }
			matNT &operator *= (const matNT &other) { matrixMulti<N*N - 1>(*this, other); return *this; }

			static matNT identity();

			T &operator[] (size_t index) { return _mat[index]; }
			const T operator[] (size_t index) const { return _mat[index]; }

			matNT()
			{
				memset(&_mat, 0, N*N*sizeof(T));
			}
		};

	}
}

#endif