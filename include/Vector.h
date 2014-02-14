#ifndef __MATHEMATICAL_VECTOR_H_
#define __MATHEMATICAL_VECTOR_H_

#include <cmath>
#include <cstring>
#include "TemplateExpressions.h"

namespace mathematical {
	namespace temps {
		// 2 Element Vector
		template <typename T>
		class vec2T {
			typedef ArithmeticOps<T>  arith;
			typedef BooleanOps<T>	  boolean;
			typedef MetaExp<vec2T, T> meta;

			T _vec[2];
		public:
			T &x, &y;	// Convience Alias

			// Vector Vector Operators
			vec2T &operator += (const vec2T &other) { meta::execute<1>(*this, other, arith::opPlus);   return *this; }
			vec2T &operator -= (const vec2T &other) { meta::execute<1>(*this, other, arith::opMinus);  return *this; }
			vec2T &operator *= (const vec2T &other) { meta::execute<1>(*this, other, arith::opMulti);  return *this; }
			vec2T &operator /= (const vec2T &other) { meta::execute<1>(*this, other, arith::opDivide); return *this; }

			// Vector Scaler Operators
			vec2T &operator += (T value) { meta::execute<1>(*this, value, arith::opPlus);   return *this; }
			vec2T &operator -= (T value) { meta::execute<1>(*this, value, arith::opMinus);  return *this; }
			vec2T &operator *= (T value) { meta::execute<1>(*this, value, arith::opMulti);  return *this; }
			vec2T &operator /= (T value) { meta::execute<1>(*this, value, arith::opDivide); return *this; }

			// Boolean Operators
			bool operator == (const vec2T &other) { return meta::test(*this, other, boolean::opEquals); }
			bool operator != (const vec2T &other) { return !(*this == other); }

			T &operator [] (size_t index) { return _vec[index]; }
			const T operator [] (size_t index) const { return _vec[index]; }

			// Vector Related Functions
			inline T dot(const vec2T &other){ return meta::sum<1>(*this, other, arith::opPlus, arith::opMulti); }
			inline T lengthsqrd()		{ return dot(*this); }
			inline T length()			{ return sqrt(lengthsqrd()); }
			inline void normalize()		{ *this /= length(); }

			// Default Constructor, Initializes all elements to 0.
			vec2T() : x(_vec[0]), y(_vec[1]) { memset(&_vec, 0, 2 * sizeof T); }
			// Single Constructor, Initializes all elements to the value.
			vec2T(T v) : vec2T() { _vec[0] = v; _vec[1] = v; }
			// Element Constructor, Initializes all elements to the given element values.
			vec2T(T x, T y) : vec2T() { _vec[0] = x; _vec[1] = y; }
		};

		// Binary Operators
		template <typename T> vec2T<T> &operator + (vec2T<T> lhs, const vec2T<T> rhs) { return lhs += rhs; }
		template <typename T> vec2T<T> &operator - (vec2T<T> lhs, const vec2T<T> rhs) { return lhs -= rhs; }
		template <typename T> vec2T<T> &operator * (vec2T<T> lhs, const vec2T<T> rhs) { return lhs *= rhs; }
		template <typename T> vec2T<T> &operator / (vec2T<T> lhs, const vec2T<T> rhs) { return lhs /= rhs; }

		template <typename T> vec2T<T> &operator + (vec2T<T> lhs, T rhs) { return lhs += rhs; }
		template <typename T> vec2T<T> &operator - (vec2T<T> lhs, T rhs) { return lhs -= rhs; }
		template <typename T> vec2T<T> &operator * (vec2T<T> lhs, T rhs) { return lhs *= rhs; }
		template <typename T> vec2T<T> &operator / (vec2T<T> lhs, T rhs) { return lhs /= rhs; }

		// 3 Element Vector
		template <typename T>
		class vec3T {
			typedef ArithmeticOps<T>  arith;
			typedef BooleanOps<T>	  boolean;
			typedef MetaExp<vec3T, T> meta;

			T _vec[3];
		public:
			T &x, &y, &z;	// Convience Alias

			// Vector Vector Operators
			vec3T &operator += (const vec3T &other) { meta::execute<2>(*this, other, arith::opPlus);   return *this; }
			vec3T &operator -= (const vec3T &other) { meta::execute<2>(*this, other, arith::opMinus);  return *this; }
			vec3T &operator *= (const vec3T &other) { meta::execute<2>(*this, other, arith::opMulti);  return *this; }
			vec3T &operator /= (const vec3T &other) { meta::execute<2>(*this, other, arith::opDivide); return *this; }

			// Vector Scaler Operators
			vec3T &operator += (T value) { meta::execute<2>(*this, value, arith::opPlus);   return *this; }
			vec3T &operator -= (T value) { meta::execute<2>(*this, value, arith::opMinus);  return *this; }
			vec3T &operator *= (T value) { meta::execute<2>(*this, value, arith::opMulti);  return *this; }
			vec3T &operator /= (T value) { meta::execute<2>(*this, value, arith::opDivide); return *this; }

			// Boolean Operators
			bool operator == (const vec3T &other) { return meta::test(*this, other, boolean::opEquals); }
			bool operator != (const vec3T &other) { return !(*this == other); }

			T &operator [] (size_t index) { return _vec[index]; }
			const T operator [] (size_t index) const { return _vec[index]; }

			// Vector Related Functions
			inline T dot(const vec3T &other){ return meta::sum<2>(*this, other, arith::opPlus, arith::opMulti); }
			inline T lengthsqrd()		{ return dot(*this); }
			inline T length()			{ return sqrt(lengthsqrd()); }
			inline void normalize()		{ *this /= length(); }

			inline vec3T cross(const vec3T &other) {
				return vec3T(y * other.z - z * other.y, -(x * other.z - z * other.x), x * other.y - y * other.x);
			}

			// Default Constructor, Initializes all elements to 0.
			vec3T() : x(_vec[0]), y(_vec[1]), z(_vec[2]) { memset(&_vec, 0, 2 * sizeof T); }
			// Single Constructor, Initializes all elements to the value.
			vec3T(T v) : vec3T() { _vec[0] = v; _vec[1] = v; _vec[2] = v; }
			// Element Constructor, Initializes all elements to the given element values.
			vec3T(T x, T y, T z) : vec3T() { _vec[0] = x; _vec[1] = y; _vec[2] = z; }
		};

		// Binary Operators
		template <typename T> vec3T<T> &operator + (vec3T<T> lhs, const vec3T<T> rhs) { return lhs += rhs; }
		template <typename T> vec3T<T> &operator - (vec3T<T> lhs, const vec3T<T> rhs) { return lhs -= rhs; }
		template <typename T> vec3T<T> &operator * (vec3T<T> lhs, const vec3T<T> rhs) { return lhs *= rhs; }
		template <typename T> vec3T<T> &operator / (vec3T<T> lhs, const vec3T<T> rhs) { return lhs /= rhs; }

		template <typename T> vec3T<T> &operator + (vec3T<T> lhs, T rhs) { return lhs += rhs; }
		template <typename T> vec3T<T> &operator - (vec3T<T> lhs, T rhs) { return lhs -= rhs; }
		template <typename T> vec3T<T> &operator * (vec3T<T> lhs, T rhs) { return lhs *= rhs; }
		template <typename T> vec3T<T> &operator / (vec3T<T> lhs, T rhs) { return lhs /= rhs; }

		// 4 Element Vector
		template <typename T>
		class vec4T {
			typedef ArithmeticOps<T>  arith;
			typedef BooleanOps<T>	  boolean;
			typedef MetaExp<vec4T, T> meta;

			T _vec[4];
		public:
			T &x, &y, &z, &w;	// Convience Alias

			// Vector Vector Operators
			vec4T &operator += (const vec4T &other) { meta::execute<3>(*this, other, arith::opPlus);   return *this; }
			vec4T &operator -= (const vec4T &other) { meta::execute<3>(*this, other, arith::opMinus);  return *this; }
			vec4T &operator *= (const vec4T &other) { meta::execute<3>(*this, other, arith::opMulti);  return *this; }
			vec4T &operator /= (const vec4T &other) { meta::execute<3>(*this, other, arith::opDivide); return *this; }

			// Vector Scaler Operators
			vec4T &operator += (T value) { meta::execute<3>(*this, value, arith::opPlus);   return *this; }
			vec4T &operator -= (T value) { meta::execute<3>(*this, value, arith::opMinus);  return *this; }
			vec4T &operator *= (T value) { meta::execute<3>(*this, value, arith::opMulti);  return *this; }
			vec4T &operator /= (T value) { meta::execute<3>(*this, value, arith::opDivide); return *this; }

			// Boolean Operators
			bool operator == (const vec4T &other) { return meta::test(*this, other, boolean::opEquals); }
			bool operator != (const vec4T &other) { return !(*this == other); }

			T &operator [] (size_t index) { return _vec[index]; }
			const T operator [] (size_t index) const { return _vec[index]; }

			// Vector Related Functions
			inline T dot(const vec4T &other){ return meta::sum<3>(*this, other, arith::opPlus, arith::opMulti); }
			inline T lengthsqrd()		{ return dot(*this); }
			inline T length()			{ return sqrt(lengthsqrd()); }
			inline void normalize()		{ *this /= length(); }

			// Default Constructor, Initializes all elements to 0.
			vec4T() : x(_vec[0]), y(_vec[1]), z(_vec[2]), w(_vec[3]) { memset(&_vec, 0, 2 * sizeof T); }
			// Single Constructor, Initializes all elements to the value.
			vec4T(T v) : vec4T() { _vec[0] = v, _vec[1] = v, _vec[2] = v, _vec[3] = v }
			// Element Constructor, Initializes all elements to the given element values.
			vec4T(T x, T y, T z, T w) : vec4T() { _vec[0] = x, _vec[1] = y, _vec[2] = z, _vec[3] = w }
		};

		// Binary Operators
		template <typename T> vec4T<T> &operator + (vec4T<T> lhs, const vec4T<T> rhs) { return lhs += rhs; }
		template <typename T> vec4T<T> &operator - (vec4T<T> lhs, const vec4T<T> rhs) { return lhs -= rhs; }
		template <typename T> vec4T<T> &operator * (vec4T<T> lhs, const vec4T<T> rhs) { return lhs *= rhs; }
		template <typename T> vec4T<T> &operator / (vec4T<T> lhs, const vec4T<T> rhs) { return lhs /= rhs; }

		template <typename T> vec4T<T> &operator + (vec4T<T> lhs, T rhs) { return lhs += rhs; }
		template <typename T> vec4T<T> &operator - (vec4T<T> lhs, T rhs) { return lhs -= rhs; }
		template <typename T> vec4T<T> &operator * (vec4T<T> lhs, T rhs) { return lhs *= rhs; }
		template <typename T> vec4T<T> &operator / (vec4T<T> lhs, T rhs) { return lhs /= rhs; }

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