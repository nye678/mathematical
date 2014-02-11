#ifndef __MATHEMATICAL_MATRIX_H_
#define __MATHEMATICAL_MATRIX_H_

#include "TemplateExpressions.h"
#include "Vector.h"

namespace mathematical {
	namespace temps {
		
		template <int N, typename T>
		class matNT {
			template <int I>
			static inline matrixMulti(matNT &lhs, const matNT &rhs) {
				size_t row = I % N;
				size_t col = I / N;
				T dot = lhs[row] * rhs[col] + lhs[row + N] * rhs[col] + lhs[row + N + N]
			}

			typedef ArithmeticOps<T>	arith;
			typedef BooleanOps<T>		boolean;
			typedef MetaExp<vecNT, T>	meta;
		protected:
			T _mat[N*N];

		public:
			matNT &operator += (const matNT &other) { meta::execute<N - 1>(*this, other, arith::opPlus);  return *this; }
			matNT &operator -= (const matNT &other) { meta::execute<N - 1>(*this, other, arith::opMinus); return *this; }
			matNT &operator *= (const matNT &other);

			static matNT identity();
		};

	}
}

#endif