#ifndef __MATHEMATICAL_VECTOR_H_
#define __MATHEMATICAL_VECTOR_H_

#include <cmath>
#include <cstring>
#include "TemplateExpressions.h"

namespace mathematical {
	namespace temps {

		// Forward Declarations
		template <typename T> class vec2T;
		template <typename T> class vec3T;
		template <typename T> class vec4T;

		// 2 Element Vector
		template <typename T>
		class vec2T {
			T _vec[2];
		public:
			T &x, &y;	// Convenience Alias

			// Vector Vector Operators
			vec2T &operator += (const vec2T &other) { MetaExp<vec2T,T>::execute<1>(*this, other, ArithmeticOps<T>::opPlus);   return *this; }
			vec2T &operator -= (const vec2T &other) { MetaExp<vec2T,T>::execute<1>(*this, other, ArithmeticOps<T>::opMinus);  return *this; }
			vec2T &operator *= (const vec2T &other) { MetaExp<vec2T,T>::execute<1>(*this, other, ArithmeticOps<T>::opMulti);  return *this; }
			vec2T &operator /= (const vec2T &other) { MetaExp<vec2T,T>::execute<1>(*this, other, ArithmeticOps<T>::opDivide); return *this; }

			// Vector Scaler Operators
			vec2T &operator += (T value) { MetaExp<vec2T, T>::execute<1>(*this, value, ArithmeticOps<T>::opPlus);   return *this; }
			vec2T &operator -= (T value) { MetaExp<vec2T, T>::execute<1>(*this, value, ArithmeticOps<T>::opMinus);  return *this; }
			vec2T &operator *= (T value) { MetaExp<vec2T, T>::execute<1>(*this, value, ArithmeticOps<T>::opMulti);  return *this; }
			vec2T &operator /= (T value) { MetaExp<vec2T, T>::execute<1>(*this, value, ArithmeticOps<T>::opDivide); return *this; }

			// Boolean Operators
			bool operator == (const vec2T &other) { return MetaExp<vec2T, T>::test(*this, other, BooleanOps<T>::opEquals); }
			bool operator != (const vec2T &other) { return !(*this == other); }

			T &operator [] (size_t index) { return _vec[index]; }
			const T operator [] (size_t index) const { return _vec[index]; }

			// Vector Related Functions
			inline T dot(const vec2T &other){ return MetaExp<vec2T, T>::sum<1>(*this, other, ArithmeticOps<T>::opPlus, ArithmeticOps<T>::opMulti); }
			inline T lengthsqrd()		{ return dot(*this); }
			inline T length()			{ return sqrt(lengthsqrd()); }
			inline void normalize()		{ *this /= length(); }

			// Default Constructor, Initializes all elements to 0.
			vec2T() : x(_vec[0]), y(_vec[1]) { memset(&_vec, 0, 2 * sizeof T); }
			// Single Constructor, Initializes all elements to the value.
			vec2T(T v) : vec2T() { _vec[0] = v; _vec[1] = v; }
			// Element Constructor, Initializes all elements to the given element values.
			vec2T(T x, T y) : vec2T() { _vec[0] = x; _vec[1] = y; }
			// Copy Constructor
			vec2T(const vec2T &other) : x(_vec[0]), y(_vec[1]) { memcpy(&_vec, &other._vec, 2 * sizeof T); }
			// Vector Constructor
			vec2T(const vec3T<T> &vec) : vec2T() { _vec[0] = vec.x; _vec[1] = vec.y; }
			vec2T(const vec4T<T> &vec) : vec2T() { _vec[0] = vec.x; _vec[1] = vec.y; }
		};

		// Binary Operators
		template <typename T> inline vec2T<T> operator + (vec2T<T> lhs, const vec2T<T> rhs) { return lhs += rhs; }
		template <typename T> inline vec2T<T> operator - (vec2T<T> lhs, const vec2T<T> rhs) { return lhs -= rhs; }
		template <typename T> inline vec2T<T> operator * (vec2T<T> lhs, const vec2T<T> rhs) { return lhs *= rhs; }
		template <typename T> inline vec2T<T> operator / (vec2T<T> lhs, const vec2T<T> rhs) { return lhs /= rhs; }

		template <typename T> inline vec2T<T> operator + (vec2T<T> lhs, T rhs) { return lhs += rhs; }
		template <typename T> inline vec2T<T> operator - (vec2T<T> lhs, T rhs) { return lhs -= rhs; }
		template <typename T> inline vec2T<T> operator * (vec2T<T> lhs, T rhs) { return lhs *= rhs; }
		template <typename T> inline vec2T<T> operator / (vec2T<T> lhs, T rhs) { return lhs /= rhs; }

		// 3 Element Vector
		template <typename T>
		class vec3T {
			T _vec[3];
		public:
			T &x, &y, &z;	// Convenience Alias

			// Vector Vector Operators
			vec3T &operator += (const vec3T &other) { MetaExp<vec3T,T>::execute<2>(*this, other, ArithmeticOps<T>::opPlus);   return *this; }
			vec3T &operator -= (const vec3T &other) { MetaExp<vec3T,T>::execute<2>(*this, other, ArithmeticOps<T>::opMinus);  return *this; }
			vec3T &operator *= (const vec3T &other) { MetaExp<vec3T,T>::execute<2>(*this, other, ArithmeticOps<T>::opMulti);  return *this; }
			vec3T &operator /= (const vec3T &other) { MetaExp<vec3T,T>::execute<2>(*this, other, ArithmeticOps<T>::opDivide); return *this; }

			// Vector Scaler Operators
			vec3T &operator += (T value) { MetaExp<vec3T, T>::execute<2>(*this, value, ArithmeticOps<T>::opPlus);   return *this; }
			vec3T &operator -= (T value) { MetaExp<vec3T, T>::execute<2>(*this, value, ArithmeticOps<T>::opMinus);  return *this; }
			vec3T &operator *= (T value) { MetaExp<vec3T, T>::execute<2>(*this, value, ArithmeticOps<T>::opMulti);  return *this; }
			vec3T &operator /= (T value) { MetaExp<vec3T, T>::execute<2>(*this, value, ArithmeticOps<T>::opDivide); return *this; }

			// Boolean Operators
			bool operator == (const vec3T &other) { return  MetaExp<vec3T, T>::test(*this, other, BooleanOps<T>::opEquals); }
			bool operator != (const vec3T &other) { return !(*this == other); }

			T &operator [] (size_t index) { return _vec[index]; }
			const T operator [] (size_t index) const { return _vec[index]; }

			// Vector Related Functions
			inline T dot(const vec3T &other) { return  MetaExp<vec3T, T>::sum<2>(*this, other, ArithmeticOps<T>::opPlus, ArithmeticOps<T>::opMulti); }
			inline T lengthsqrd()			 { return dot(*this); }
			inline T length()				 { return sqrt(lengthsqrd()); }
			inline vec3T normalize()		 { *this /= length(); return *this; }

			inline vec3T cross(const vec3T &other) {
				return vec3T(y * other.z - z * other.y, -(x * other.z - z * other.x), x * other.y - y * other.x);
			}

			// Default Constructor, Initializes all elements to 0.
			vec3T() : x(_vec[0]), y(_vec[1]), z(_vec[2]) { memset(&_vec, 0, 2 * sizeof T); }
			// Single Constructor, Initializes all elements to the value.
			vec3T(T v) : vec3T() { _vec[0] = v; _vec[1] = v; _vec[2] = v; }
			// Element Constructor, Initializes all elements to the given element values.
			vec3T(T x, T y, T z) : vec3T() { _vec[0] = x; _vec[1] = y; _vec[2] = z; }
			// Copy Constructor
			vec3T(const vec3T &other) : x(_vec[0]), y(_vec[1]), z(_vec[2]) { memcpy(&_vec, &other._vec, 3 * sizeof T); }
			// Vector Constructor
			vec3T(const vec2T<T> &vec, T z = 0) : vec3T() { _vec[0] = vec.x; _vec[1] = vec.y; _vec[2] = z; }
			vec3T(T x, const vec2T<T> &vec) : vec3T() { _vec[0] = x; _vec[1] = vec.x; _vec[2] = vec.y; }
			vec3T(const vec4T<T> &vec) : vec3T() { _vec[0] = vec.x; _vec[1] = vec.y; _vec[2] = vec.z; }

			static vec3T normalize(vec3T vec) { return vec.normalize(); }
		};

		// Binary Operators
		template <typename T> inline vec3T<T> operator + (vec3T<T> lhs, const vec3T<T> rhs) { return lhs += rhs; }
		template <typename T> inline vec3T<T> operator - (vec3T<T> lhs, const vec3T<T> rhs) { return lhs -= rhs; }
		template <typename T> inline vec3T<T> operator * (vec3T<T> lhs, const vec3T<T> rhs) { return lhs *= rhs; }
		template <typename T> inline vec3T<T> operator / (vec3T<T> lhs, const vec3T<T> rhs) { return lhs /= rhs; }

		template <typename T> inline vec3T<T> operator + (vec3T<T> lhs, T rhs) { return lhs += rhs; }
		template <typename T> inline vec3T<T> operator - (vec3T<T> lhs, T rhs) { return lhs -= rhs; }
		template <typename T> inline vec3T<T> operator * (vec3T<T> lhs, T rhs) { return lhs *= rhs; }
		template <typename T> inline vec3T<T> operator / (vec3T<T> lhs, T rhs) { return lhs /= rhs; }

		// 4 Element Vector
		template <typename T>
		class vec4T {
			T _vec[4];
		public:
			T &x, &y, &z, &w;	// Convenience Alias

			// Vector Vector Operators
			vec4T &operator += (const vec4T &other) { MetaExp<vec4T, T>::execute<3>(*this, other, ArithmeticOps<T>::opPlus);   return *this; }
			vec4T &operator -= (const vec4T &other) { MetaExp<vec4T, T>::execute<3>(*this, other, ArithmeticOps<T>::opMinus);  return *this; }
			vec4T &operator *= (const vec4T &other) { MetaExp<vec4T, T>::execute<3>(*this, other, ArithmeticOps<T>::opMulti);  return *this; }
			vec4T &operator /= (const vec4T &other) { MetaExp<vec4T, T>::execute<3>(*this, other, ArithmeticOps<T>::opDivide); return *this; }

			// Vector Scaler Operators
			vec4T &operator += (T value) { MetaExp<vec4T, T>::execute<3>(*this, value, ArithmeticOps<T>::opPlus);   return *this; }
			vec4T &operator -= (T value) { MetaExp<vec4T, T>::execute<3>(*this, value, ArithmeticOps<T>::opMinus);  return *this; }
			vec4T &operator *= (T value) { MetaExp<vec4T, T>::execute<3>(*this, value, ArithmeticOps<T>::opMulti);  return *this; }
			vec4T &operator /= (T value) { MetaExp<vec4T, T>::execute<3>(*this, value, ArithmeticOps<T>::opDivide); return *this; }

			// Boolean Operators
			bool operator == (const vec4T &other) { return MetaExp<vec4T, T>::test(*this, other, BooleanOps<T>::opEquals); }
			bool operator != (const vec4T &other) { return !(*this == other); }

			T &operator [] (size_t index) { return _vec[index]; }
			const T operator [] (size_t index) const { return _vec[index]; }

			// Vector Related Functions
			inline T dot(const vec4T &other){ return MetaExp<vec4T, T>::sum<3>(*this, other, ArithmeticOps<T>::opPlus, ArithmeticOps<T>::opMulti); }
			inline T lengthsqrd()		{ return dot(*this); }
			inline T length()			{ return sqrt(lengthsqrd()); }
			inline void normalize()		{ *this /= length(); }

			// Default Constructor, Initializes all elements to 0.
			vec4T() : x(_vec[0]), y(_vec[1]), z(_vec[2]), w(_vec[3]) { memset(&_vec, 0, 2 * sizeof T); }
			// Single Constructor, Initializes all elements to the value.
			vec4T(T v) : vec4T() { _vec[0] = v; _vec[1] = v; _vec[2] = v; _vec[3] = v; }
			// Element Constructor, Initializes all elements to the given element values.
			vec4T(T x, T y, T z, T w) : vec4T() { _vec[0] = x; _vec[1] = y; _vec[2] = z; _vec[3] = w; }
			// Copy Constructor
			vec4T(const vec4T &other) : x(_vec[0]), y(_vec[1]), z(_vec[2]), w(_vec[3]) { memcpy(&_vec, &other._vec, 4 * sizeof T); }
			// Vector Contructors
			vec4T(const vec3T<T> &vec, T w = 1) : vec4T() { _vec[0] = vec.x; _vec[1] = vec.y; _vec[2] = vec.z; _vec[3] = w; }
			vec4T(T x, const vec3T<T> &vec) : vec4T() { _vec[0] = x; _vec[1] = vec.x; _vec[2] = vec.y; _vec[3] = vec.z; }
			vec4T(const vec2T<T> &vec, T z = 0, T w = 1) : vec4T() { _vec[0] = vec.x; _vec[1] = vec.y; _vec[2] = z; _vec[3] = w; }
			vec4T(T x, const vec2T<T> &vec, T w = 1) : vec4T() { _vec[0] = x; _vec[1] = vec.x; _vec[2] = vec.y; _vec[3] = w; }
			vec4T(T x, T y, const vec2T<T> &vec) : vec4T() { _vec[0] = x; _vec[1] = y; _vec[2] = vec.x; _vec[3] = vec.y; }
			vec4T(const vec2T<T> &v1, const vec2T<T> &v2) : vec4T() { _vec[0] = v1.x; _vec[1] = v1.y; _vec[2] = v2.x; _vec[3] = v2.y; }
		};

		// Binary Operators
		template <typename T> inline vec4T<T> operator + (vec4T<T> lhs, const vec4T<T> rhs) { return lhs += rhs; }
		template <typename T> inline vec4T<T> operator - (vec4T<T> lhs, const vec4T<T> rhs) { return lhs -= rhs; }
		template <typename T> inline vec4T<T> operator * (vec4T<T> lhs, const vec4T<T> rhs) { return lhs *= rhs; }
		template <typename T> inline vec4T<T> operator / (vec4T<T> lhs, const vec4T<T> rhs) { return lhs /= rhs; }

		template <typename T> inline vec4T<T> operator + (vec4T<T> lhs, T rhs) { return lhs += rhs; }
		template <typename T> inline vec4T<T> operator - (vec4T<T> lhs, T rhs) { return lhs -= rhs; }
		template <typename T> inline vec4T<T> operator * (vec4T<T> lhs, T rhs) { return lhs *= rhs; }
		template <typename T> inline vec4T<T> operator / (vec4T<T> lhs, T rhs) { return lhs /= rhs; }

	}

	// Type Definitions for the user!

	// 2 Element Float Vector
	typedef temps::vec2T<float> vec2f;
	// 3 Element Float Vector
	typedef temps::vec3T<float> vec3f;
	// 4 Element Float Vector
	typedef temps::vec4T<float> vec4f;
	// 2 Element Double Vector
	typedef temps::vec2T<double> vec2d;
	// 3 Element Double Vector
	typedef temps::vec3T<double> vec3d;
	// 4 Element Double Vector
	typedef temps::vec4T<double> vec4d;
}

#endif