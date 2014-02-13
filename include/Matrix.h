#ifndef __MATHEMATICAL_MATRIX_H_
#define __MATHEMATICAL_MATRIX_H_

#include <cmath>
#include <cassert>
#include <initializer_list>

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

			template <int I>
			static inline void diagonal(matNT &matrix, T value)
			{
				matrix[I*(N + 1)] = value;
				return diagonal<I - 1>(matrix, value);
			}

			template <>
			static inline void diagonal<0>(matNT &matrix, T value)
			{
				matrix[0] = value;
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

			T &operator[] (size_t index) { return _mat[index]; }
			const T operator[] (size_t index) const { return _mat[index]; }

			matNT()
			{
				memset(&_mat, 0, N*N*sizeof(T));
			}

			matNT(T value) : matNT()
			{
				diagonal<N - 1>(*this, value);
			}

			matNT(std::initializer_list<T> list) : matNT()
			{
				assert(list.size() <= N*N);
				size_t index = 0;
				for (auto item : list) 
				{
					_mat[index] = item;
					index++;
				}
			}

			static matNT identity() { return matNT(1); }
		};

		template <typename T>
		class mat2T : public matNT<2, T> {

		};

		template <typename T>
		class mat3T : public matNT<3, T> {

		};

		template <typename T>
		class mat4T : public matNT<4, T> {
		public:
			mat4T() : matNT<4, T>() {}
			mat4T(T value) : matNT<4, T>(value) {}
			mat4T(std::initializer_list<T> list) : mat4NT<4, T>(list) {}
		};

		template <typename T>
		mat4T<T> translation(T x, T y, T z) {
			mat4T<T> matrix = mat4T<T>(1);
			matrix[12] = x;
			matrix[13] = y;
			matrix[14] = z;
			return matrix;
		}

		template <typename T>
		mat4T<T> rotation(T rx, T ry, T rz) {
			mat4<T> matrix = {
				cos(rx)*cos(rz), cos(rx)*sin(rz) + sin(rx)*sin(ry)*cos(rz), sin(rx)*sin(rz) - cos(rx)*sin(ry)*cos(rz), 0,
				-cos(ry)*sin(rz), cos(rx)*cos(rz) - sin(rx)*sin(ry)*sin(rz), sin(rx)*cos(rz) + cos(rx)*sin(ry)*sin(rz), 0,
				sin(ry), -sin(rx)*cos(ry), cos(rx)*cos(ry), 0,
				0, 0, 0, 1
			};
		}

		template <typename T>
		mat4T<T> scale(T sx, T sy, T sz) {
			mat4T<T> matrix = mat4T<T>();
			matrix[0] = sx;
			matrix[5] = sy;
			matrix[10] = sz;
			matrix[15] = 1;
		}
	}

	typedef temps::mat2T<float> mat2f;
	typedef temps::mat3T<float> mat3f;
	typedef temps::mat4T<float> mat4f;

	typedef temps::mat2T<double> mat2d;
	typedef temps::mat3T<double> mat3d;
	typedef temps::mat4T<double> mat4d;
}

#endif