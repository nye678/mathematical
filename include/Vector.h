#ifndef __MATHEMATICAL_VECTOR_H_
#define __MATHEMATICAL_VECTOR_H_

#include <cmath>
#include <cstring>
#include "TemplateExpressions.h"

namespace mathematical {
	namespace temps {
		

		// Base Vector Template
		// N = number of elements, T = type of elements.
		// Best to use float or double.
		template <size_t N, typename T>
		class vecNT {
			typedef ArithmeticOps<T>	arith;
			typedef BooleanOps<T>		boolean;
			typedef MetaExp<vecNT, T>	meta;
		protected:
			T _vec[N];		// Where the numbers are stored!

		public:
			// Vector Vector Operators
			vecNT &operator += (const vecNT &other) { meta::execute<N - 1>(*this, other, arith::opPlus);   return *this; }
			vecNT &operator -= (const vecNT &other) { meta::execute<N - 1>(*this, other, arith::opMinus);  return *this; }
			vecNT &operator *= (const vecNT &other) { meta::execute<N - 1>(*this, other, arith::opMulti);  return *this; }
			vecNT &operator /= (const vecNT &other) { meta::execute<N - 1>(*this, other, arith::opDivide); return *this; }
			
			// Vector Scaler Operators
			vecNT &operator += (T value) { meta::execute<N - 1>(*this, value, arith::opPlus);   return *this; }
			vecNT &operator -= (T value) { meta::execute<N - 1>(*this, value, arith::opMinus);  return *this; }
			vecNT &operator *= (T value) { meta::execute<N - 1>(*this, value, arith::opMulti);  return *this; }
			vecNT &operator /= (T value) { meta::execute<N - 1>(*this, value, arith::opDivide); return *this; }
			
			// Boolean Operators
			bool operator == (const vecNT &other) { return meta::test(*this, other, boolean::opEquals); }
			bool operator != (const vecNT &other) { return !(*this == other); }
			
			// Array Accessor Operators
				  T &operator [] (size_t index)		  { return _vec[index]; }
			const T operator  [] (size_t index) const { return _vec[index]; }

			// Vector Related Functions
			inline T dot(const vecNT &other) { return meta::sum<N - 1>(*this, other, arith::opPlus, arith::opMulti); }
			inline T lengthsqrd()			 { return dot(*this); }
			inline T length()				 { return sqrt(lengthsqrd()); }
			inline void normalize()			 { *this /= length(); }

			vecNT() { memset(&_vec, 0, N * sizeof T); }
		};

		// 2 Element Vector
		template <typename T>
		class vec2T : public vecNT<2, T>{
		public:
			T &x, &y;	// Convience Alias

			// Default Constructor, Initializes all elements to 0.
			vec2T()	: x(_vec[0]), y(_vec[1]) {}
			// Single Constructor, Initializes all elements to the value.
			vec2T(T v) : vec2T() { _vec[0] = v; _vec[1] = v; }
			// Element Constructor, Initializes all elements to the given element values.
			vec2T(T x, T y) : vec2T() { _vec[0] = x; _vec[1] = y; }
		};

		// 3 Element Vector
		template <typename T>
		class vec3T : public vecNT<3, T>{
		public:
			T &x, &y, &z;	// Convience Alias

			// Cross Product
			inline vec3T cross(const vec3T &other) { 
				return vec3T(y * other.z - z * other.y, -(x * other.z - z * other.x), x * other.y - y * other.x); 
			}

			// Default Constructor, Initializes all elements to 0.
			vec3T() : x(_vec[0]), y(_vec[1]), z(_vec[2]) {}
			// Single Constructor, Initializes all elements to the value.
			vec3T(T v) : vec3T() { _vec[0] = v; _vec[1] = v; _vec[2] = v; }
			// Element Constructor, Initializes all elements to the given element values.
			vec3T(T x, T y, T z) : vec3T() { _vec[0] = x; _vec[1] = y; _vec[2] = z; }
		};

		// 4 Element Vector
		template <typename T>
		class vec4T : public vecNT<4, T>{
		public:
			T &x, &y, &z, &w;	// Convience Alias

			// Default Constructor, Initializes all elements to 0.
			vec4T() : x(_vec[0]), y(_vec[1]), z(_vec[2]), w(_vec[3]) {}
			// Single Constructor, Initializes all elements to the value.
			vec4T(T v) : vec4T() { _vec[0] = v, _vec[1] = v, _vec[2] = v, _vec[3] = v}
			// Element Constructor, Initializes all elements to the given element values.
			vec4T(T x, T y, T z, T w)  : vec4T() { _vec[0] = x, _vec[1] = y, _vec[2] = z, _vec[3] = w}
		};
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