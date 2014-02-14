#ifndef __MATHEMATICAL_MATRIX_H_
#define __MATHEMATICAL_MATRIX_H_

#include <cmath>
#include <cassert>
#include <initializer_list>

#include "TemplateExpressions.h"

namespace mathematical {
	namespace temps {
		template <typename T>
		class mat2T {
			T _mat[4];
		public:
			// Matrix Matrix Operators
			mat2T &operator += (const mat2T &other) { MetaExp<mat2T,T>::execute<3>(*this, other, ArithmeticOps<T>::opPlus);  return *this; }
			mat2T &operator -= (const mat2T &other) { MetaExp<mat2T,T>::execute<3>(*this, other, ArithmeticOps<T>::opMinus); return *this; }
			mat2T &operator *= (const mat2T &other) { MatrixMeta<mat2T,T,2>::matrixMulti<3>(*this, other); return *this; }

			// Matrix Scaler Operators
			mat2T &operator *= (T value) { MetaExp<mat2T,T>::execute<3>(*this, value, ArithmeticOps<T>::opMulti);  return *this; }
			mat2T &operator /= (T value) { MetaExp<mat2T,T>::execute<3>(*this, value, ArithmeticOps<T>::opDivide); return *this; }

			// Boolean Operators
			bool operator == (const mat2T &other) const { return MetaExp<mat2T, T>::test<3>(*this, other, BooleanOps<T>::opEquals); }
			bool operator != (const mat2T &other) const { return !(*this == other); }

			// Element Access Operators
			T &operator[] (size_t index) { return _mat[index]; }
			const T operator[] (size_t index) const { return _mat[index]; }

			// Matrix Related Methods
			mat2T &transpose() { std::swap(_mat[1], _mat[2]); return *this; }
			T determinate() { return _mat[0] * _mat[3] - _mat[2] * _mat[1]; }

			// Default Constructor
			mat2T() { memset(&_mat, 0, 4 * sizeof T); }
			// Diagonal Constructor
			mat2T(T value) : mat2T() { _mat[0] = value; _mat[3] = value; }
			// Copy Constructor
			mat2T(const mat2T &other) { memcpy(&_mat, &other._mat, 4 * sizeof T); }
			// Initializer List Constructor
			mat2T(std::initializer_list<T> list) {
				size_t index = 0;
				size_t row = 0;
				
				for (auto item : list)
				{
					_mat[row + index] = item;
					index += 2;
					if (index >= 4) { row++; index = 0; }
				}
			}

			// Identity Matrix
			static mat2T identity() { return mat2T(1); }
			// Rotation Matrix
			static mat2T rotation(T angle) { return mat2T({	cos(angle), sin(angle), sin(angle),  cos(angle) }); }
			// Scale Matrix
			static mat2T scale(T sx, T sy) { return mat2T({ sx, 0, 0, sy }); }
			// Transpose Matrix
			static mat2T transpose(mat2T mat) { return mat.transpose(); }
 		};

		template <typename T> inline mat2T<T> operator + (mat2T<T> lhs, const mat2T<T> &rhs) { return lhs += rhs; }
		template <typename T> inline mat2T<T> operator - (mat2T<T> lhs, const mat2T<T> &rhs) { return lhs -= rhs; }
		template <typename T> inline mat2T<T> operator * (mat2T<T> lhs, const mat2T<T> &rhs) { return lhs *= rhs; }

		template <typename T> inline mat2T<T> operator * (mat2T<T> lhs, T rhs) { return lhs *= rhs; }

		template <typename T> inline vec2T<T> operator * (const mat2T<T> &mat, const vec2T<T> &vec) {
			return vec2T<T>(
				vec.x * mat[0] + vec.y * mat[2],
				vec.x * mat[1] + vec.y * mat[3]
				);
		}

		template <typename T>
		class mat3T {
			T _mat[9];
		public:
			// Matrix Matrix Operators
			mat3T &operator += (const mat3T &other) { MetaExp<mat2T, T>::execute<8>(*this, other, ArithmeticOps<T>::opPlus);  return *this; }
			mat3T &operator -= (const mat3T &other) { MetaExp<mat2T, T>::execute<8>(*this, other, ArithmeticOps<T>::opMinus); return *this; }
			mat3T &operator *= (const mat3T &other) { MatrixMeta<mat2T, T, 3>::matrixMulti<8>(*this, other); return *this; }

			// Matrix Scaler Operators
			mat3T &operator *= (T value) { MetaExp<mat3T, T>::execute<8>(*this, value, ArithmeticOps<T>::opMulti);  return *this; }
			mat3T &operator /= (T value) { MetaExp<mat3T, T>::execute<8>(*this, value, ArithmeticOps<T>::opDivide); return *this; }

			// Boolean Operators
			bool operator == (const mat3T &other) const { return MetaExp<mat3T, T>::test<8>(*this, other, BooleanOps<T>::opEquals); }
			bool operator != (const mat3T &other) const { return !(*this == other); }

			// Element Access Operators
			T &operator[] (size_t index) { return _mat[index]; }
			const T operator[] (size_t index) const { return _mat[index]; }

			// Matrix Related Methods
			mat3T &transpose() { 
				std::swap(_mat[1], _mat[3]); 
				std::swap(_mat[2], _mat[6]);
				std::swap(_mat[5], _mat[7]);
				return *this; 
			}
			
			T determinate() { 
				// (aei + bfg + cdh) - (ceg + bdi + afh).
				// a 0, b 3, c 6, d 1, e 4, f 7, g 2, h 5, i 8
				return (_mat[0] * _mat[4] * _mat[8] + _mat[3] * _mat[7] * _mat[2] + _mat[6] * _mat[1] * _mat[5]) -
					(_mat[6] * _mat[4] * _mat[2] + _mat[3] * _mat[1] * _mat[8] + _mat[0] * _mat[7] * _mat[5]);
			}

			// Default Constructor
			mat3T() { memset(&_mat, 0, 9 * sizeof T); }
			// Diagonal Constructor
			mat3T(T value) : mat3T() { _mat[0] = value; _mat[4] = value; _mat[8] = value; }
			// Copy Constructor
			mat3T(const mat3T &other) { memcpy(&_mat, &other._mat, 9 * sizeof T); }
			// Initializer List Constructor
			mat3T(std::initializer_list<T> list) {
				size_t index = 0, row = 0;

				for (auto item : list)
				{
					_mat[row + index] = item;
					index += 3;
					if (index >= 9) { row++; index = 0; }
				}
			}

			// Identity Matrix
			static mat3T identity() { return mat3T(1); }
			// Rotation Matrix
			static mat3T rotation(const vec3T<T> &axis, T angle) { 
				T cosA = cos(angle);
				T sinA = cos(angle);
				vec3T<T> u = vec3T<T>::normalize(axis);
				return mat3T({
					cosA + u.x * u.x * (1 - cosA),			u.x * u.y * (1 - cosA) - u.z * sinA,	u.x * u.z * (1 - cosA) - u.y * sinA,
					u.y * u.x * (1 - cosA) + u.z * sinA,	cosA + u.y * u.y * (1 - cosA),			u.y * u.z * (1 - cosA) - u.x * sinA,
					u.z * u.x * (1 - cosA) - u.y * sinA,	u.z * u.y * (1 - cosA) + u.x * sinA,	cosA + u.z * u.z * (1 - cosA)
				}); 
			}
			// Scale Matrix
			static mat3T scale(T sx, T sy, T sz) {
				return mat2T({ sx, 0, 0, 0, sy, 0, 0, 0, sz });
			}
			// Transpose Matrix
			static mat3T transpose(mat3T mat) { return mat.transpose(); }
		};

		// Matrix Binary Operators
		template <typename T> inline mat3T<T> operator + (mat3T<T> lhs, const mat3T<T> &rhs) { return lhs += rhs; }
		template <typename T> inline mat3T<T> operator - (mat3T<T> lhs, const mat3T<T> &rhs) { return lhs -= rhs; }
		template <typename T> inline mat3T<T> operator * (mat3T<T> lhs, const mat3T<T> &rhs) { return lhs *= rhs; }
		// Scalar Binary Operators
		template <typename T> inline mat3T<T> operator * (mat3T<T> lhs, T rhs) { return lhs *= rhs; }
		// Vector Binary Operators
		template <typename T> inline vec3T<T> operator * (const mat3T<T> &mat, const vec3T<T> &vec) {
			return vec3T<T>(
				vec.x * mat[0] + vec.y * mat[3] + vec.z * mat[6],
				vec.x * mat[1] + vec.y * mat[4] + vec.z * mat[7],
				vec.x * mat[2] + vec.y * mat[5] + vec.z * mat[8],
				);
		}

		template <typename T>
		class mat4T {
			T _mat[6];
		public:
			// Matrix Matrix Operators
			mat4T &operator += (const mat4T &other) { MetaExp<mat2T, T>::execute<15>(*this, other, ArithmeticOps<T>::opPlus);  return *this; }
			mat4T &operator -= (const mat4T &other) { MetaExp<mat2T, T>::execute<15>(*this, other, ArithmeticOps<T>::opMinus); return *this; }
			mat4T &operator *= (const mat4T &other) { MatrixMeta<mat2T, T, 4>::matrixMulti<15>(*this, other); return *this; }

			// Matrix Scaler Operators
			mat4T &operator *= (T value) { MetaExp<mat4T, T>::execute<15>(*this, value, ArithmeticOps<T>::opMulti);  return *this; }
			mat4T &operator /= (T value) { MetaExp<mat4T, T>::execute<15>(*this, value, ArithmeticOps<T>::opDivide); return *this; }

			// Boolean Operators
			bool operator == (const mat4T &other) const { return MetaExp<mat4T, T>::test<15>(*this, other, BooleanOps<T>::opEquals); }
			bool operator != (const mat4T &other) const { return !(*this == other); }

			// Element Access Operators
			T &operator[] (size_t index) { return _mat[index]; }
			const T operator[] (size_t index) const { return _mat[index]; }

			// Matrix Related Methods
			mat4T &transpose() {
				std::swap(_mat[1], _mat[4]);
				std::swap(_mat[2], _mat[8]);
				std::swap(_mat[3], _mat[12]);
				std::swap(_mat[6], _mat[9]);
				std::swap(_mat[7], _mat[13]);
				std::swap(_mat[11], _mat[14]);
				return *this;
			}

			//T determinate() {
			//}

			// Default Constructor
			mat4T() { memset(&_mat, 0, 16 * sizeof T); }
			// Diagonal Constructor
			mat4T(T value) : mat4T() { _mat[0] = value; _mat[5] = value; _mat[10] = value; _mat[15] = value; }
			// Copy Constructor
			mat4T(const mat4T &other) { memcpy(&_mat, &other._mat, 16 * sizeof T); }
			// Initializer List Constructor
			mat4T(std::initializer_list<T> list) {
				size_t index = 0, row = 0;

				for (auto item : list)
				{
					_mat[row + index] = item;
					index += 4;
					if (index >= 16) { row++; index = 0; }
				}
			}

			// Identity Matrix
			static mat4T identity() { return mat4T(1); }
			// Rotation Matrix
			static mat4T rotation(const vec3T<T> &axis, T angle) {
				T cosA = cos(angle);
				T sinA = cos(angle);
				vec3T<T> u = vec3T<T>::normalize(axis);
				return mat4T({
					cosA + u.x * u.x * (1 - cosA),			u.x * u.y * (1 - cosA) - u.z * sinA,	u.x * u.z * (1 - cosA) - u.y * sinA, 0,
					u.y * u.x * (1 - cosA) + u.z * sinA,	cosA + u.y * u.y * (1 - cosA),			u.y * u.z * (1 - cosA) - u.x * sinA, 0,
					u.z * u.x * (1 - cosA) - u.y * sinA,	u.z * u.y * (1 - cosA) + u.x * sinA,	cosA + u.z * u.z * (1 - cosA),		 0,
					0,										0,										0,									 1
				});
			}
			// Scale Matrix
			static mat4T scale(T sx, T sy, T sz) {
				return mat2T({ 
					sx, 0,  0,  0, 
					0,  sy, 0,  0, 
					0,  0,  sz, 0,
					0,  0,  0,  1
				});
			}
			// Translation Matrix
			static mat4T translation(T x, T y, T z) {
				return mat2T({
					1, 0, 0, x,
					0, 1, 0, y,
					0, 0, 1, z,
					0, 0, 0, 1
				})
			}

			// Transpose Matrix
			static mat4T transpose(mat4T mat) { return mat.transpose(); }
		};

		// Matrix Binary Operators
		template <typename T> inline mat4T<T> operator + (mat4T<T> lhs, const mat4T<T> &rhs) { return lhs += rhs; }
		template <typename T> inline mat4T<T> operator - (mat4T<T> lhs, const mat4T<T> &rhs) { return lhs -= rhs; }
		template <typename T> inline mat4T<T> operator * (mat4T<T> lhs, const mat4T<T> &rhs) { return lhs *= rhs; }
		// Scalar Binary Operators
		template <typename T> inline mat4T<T> operator * (mat4T<T> lhs, T rhs) { return lhs *= rhs; }
		// Vector Binary Operators
		template <typename T> inline vec3T<T> operator * (const mat4T<T> &mat, const vec3T<T> &vec) {
			return vec3T<T>(
				vec.x * mat[0] + vec.y * mat[4] + vec.z * mat[8] + mat[12],
				vec.x * mat[1] + vec.y * mat[5] + vec.z * mat[9] + mat[13],
				vec.x * mat[2] + vec.y * mat[6] + vec.z * mat[10] + mat[14]
				);
		}
		template <typename T> inline vec3T<T> operator * (const mat4T<T> &mat, const vec4T<T> &vec) {
			return vec4T<T>(
				vec.x * mat[0] + vec.y * mat[4] + vec.z * mat[8] + vec.w * [12],
				vec.x * mat[1] + vec.y * mat[5] + vec.z * mat[9] + vec.w * [13],
				vec.x * mat[2] + vec.y * mat[6] + vec.z * mat[10] + vec.w *[14],
				vec.x * mat[3] + vec.y * mat[7] + vec.z * mat[11] + vec.w *[15]
				);
		}
	}


	typedef temps::mat2T<float> mat2f;
	/*typedef temps::mat3T<float> mat3f;
	typedef temps::mat4T<float> mat4f;*/

	typedef temps::mat2T<double> mat2d;
	/*typedef temps::mat3T<double> mat3d;
	typedef temps::mat4T<double> mat4d;*/

}

#endif