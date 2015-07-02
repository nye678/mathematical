#ifndef __MATHEMATICAL_VECTOR_H_
#define __MATHEMATICAL_VECTOR_H_

#include <cmath>
#include <cstring>
#include "TemplateExpressions.h"

namespace mathematical {
	namespace templates {

		// Forward Declarations
		template <typename T> union vec2T;
		template <typename T> union vec3T;
		template <typename T> union vec4T;

		// 2 Element Vector
		template <typename T>
		union vec2T {
			T _vec[2];
		public:
			struct { T x, y; };

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
			vec2T() = default;
			// Single Constructor, Initializes all elements to the value.
			vec2T(T v) : x(v), y(v) {}
			// Element Constructor, Initializes all elements to the given element values.
			vec2T(T x, T y) : x(x), y(y) {}
			// Copy Constructor
			vec2T(const vec2T &other) : x(other.x), y(other.y) {}
			// Vector Constructor
			vec2T(const vec3T<T> &vec) : x(vec.x), y(vec.y) {}
			vec2T(const vec4T<T> &vec) : x(vec.x), y(vec.y) {}
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
		union vec3T {
			T _vec[3];
		public:
			struct { T x, y, z; };

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
			vec3T() = default;
			// Single Constructor, Initializes all elements to the value.
			vec3T(T v) : x(v), y(v), z(v) {}
			// Element Constructor, Initializes all elements to the given element values.
			vec3T(T x, T y, T z) : x(x), y(y), z(z) {}
			// Copy Constructor
			vec3T(const vec3T &other) : x(other.x), y(other.y), z(other.z) {}
			// Vector Constructor
			vec3T(const vec2T<T> &vec, T z = 0) : x(vec.x), y(vec.y) z(z) {}
			vec3T(T x, const vec2T<T> &vec) : x(x), y(vec.x) z(vec.y) {}
			vec3T(const vec4T<T> &vec) : x(vec.x), y(vec.y) z(vec.z) {}

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
		union vec4T {
			T _vec[4];
		public:
			struct { T x, y, z, w; };

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
			vec4T() = default;
			// Single Constructor, Initializes all elements to the value.
			vec4T(T v) : x(v), y(v), z(v), w(v) {}
			// Element Constructor, Initializes all elements to the given element values.
			vec4T(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
			// Copy Constructor
			vec4T(const vec4T &other) : x(other.x), y(other.y), z(other.z), w(other.w) {}
			// Vector Contructors
			vec4T(const vec3T<T> &vec, T w = 1) : vec4T() x(vec.x), y(vec.y), z(vec.z), w(w) {}
			vec4T(T x, const vec3T<T> &vec) : vec4T() x(x), y(vec.y), z(vec.z), w(vec.w) {}
			vec4T(const vec2T<T> &vec, T z = 0, T w = 1) : vec4T() x(vec.x), y(vec.y), z(z), w(w) {}
			vec4T(T x, const vec2T<T> &vec, T w = 1) : vec4T() x(x), y(vec.x), z(vec.y), w(w) {}
			vec4T(T x, T y, const vec2T<T> &vec) : vec4T() x(x), y(y), z(vec.x), w(vec.y) {}
			vec4T(const vec2T<T> &v1, const vec2T<T> &v2) : vec4T() x(v1.x), y(v1.y), z(v2.x), w(v2.y) {}
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
	typedef templates::vec2T<float> vec2f;
	// 3 Element Float Vector
	typedef templates::vec3T<float> vec3f;
	// 4 Element Float Vector
	typedef templates::vec4T<float> vec4f;
	// 2 Element Double Vector
	typedef templates::vec2T<double> vec2d;
	// 3 Element Double Vector
	typedef templates::vec3T<double> vec3d;
	// 4 Element Double Vector
	typedef templates::vec4T<double> vec4d;
	// 2 Element Int Vector
	typedef templates::vec2T<int> vec2i;
	// 3 Element Int Vector
	typedef templates::vec3T<int> vec3i;
	// 4 Element Int Vector
	typedef templates::vec4T<int> vec4i;
}

#endif