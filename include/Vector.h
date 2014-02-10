#ifndef __MATHEMATICAL_VECTOR_H_
#define __MATHEMATICAL_VECTOR_H_

#include <cmath>
#include <cstring>

namespace mathematical {
	namespace temps {

		// Base Vector Template
		// N = number of elements, T = type of elements.
		// Best to use float or double.
		template <size_t N, typename T>
		class vecNT {
			// Arithmetic Operators 
			// Used by the Meta Expressions so operators can be passed as arguments.
			typedef T (*ArithOp)(T, T);
			static inline T opPlus  (T a, T b) { return a + b; }
			static inline T opMinus (T a, T b) { return a - b; }
			static inline T opMulti (T a, T b) { return a * b; }
			static inline T opDivide(T a, T b) { return a / b; }

			// Boolean Operators
			// Same thing as arithmetic only boolean.
			typedef bool (*BoolOp)(T, T);
			static inline bool opEquals(T a, T b) { return a == b; }

			// Meta Expressions
			// The meta expressions generate code during compilation to implement all the
			// vector operations. Meta expressions use inlining and template recusion to
			// generate the exact operations and avoid loops.

			// Meta Execute Vector Expression
			// Performs the given operation on all elements in the vectors, storing the
			// results in the first vector argument.
			template <int I> static inline void execute(vecNT &lhs, const vecNT &rhs, ArithOp op) { 
				lhs[I] = op(lhs[I], rhs[I]); 
				return execute<I - 1>(lhs, rhs, op); 
			}

			template <>static inline void execute<0>(vecNT &lhs, const vecNT &rhs, ArithOp op) { 
				lhs[0] = op(lhs[0], rhs[0]); 
			}
			
			// Meta Execute Scalar Expression
			// Same as the vector version except the second argument is a scalar and is
			// applied to all elements of the first vector using the given operation.
			template <int I> static inline void execute(vecNT &lhs, T rhs, ArithOp op) { 
				lhs[I] = op(lhs[I], rhs); 
				return execute<I - 1>(lhs, rhs, op); 
			}

			template <> static inline void execute<0>(vecNT &lhs, T rhs, ArithOp op) { 
				lhs[0] = op(lhs[0], rhs); 
			}
			
			// Meta Test Express
			// Performs some boolean operation on the two vectors, comparing element to element.
			template <int I> static inline bool test(vecNT &lhs, const vecNT &rhs, BoolOp) { 
				return op(lhs[I], rhs[I]) && test<I - 1>(lhs, rhs, op); 
			}

			template <>	static inline bool test<0>(vecNT &lhs, const vecNT &rhs, BoolOp) { 
				return op(lhs[0], rhs[0]); 
			}
			
			// Meta Sum Expression
			// Requires two operations. The 'op' operation is performed on each element, and then
			// those elements are totaled using the sumOp operation. Used for dot products mostly.
			template <int I> static inline T sum(vecNT &lhs, const vecNT &rhs, ArithOp sumOp, ArithOp op) { 
				return sumOp(op(lhs[I], rhs[I]), sum<I - 1>(lhs, rhs, sumOp, op)); 
			}

			template <> static inline T sum<0>(vecNT &lhs, const vecNT &rhs, ArithOp sumOp, ArithOp op) { 
				return op(lhs[0], rhs[0]); 
			}

		protected:
			T _vec[N];		// Where the numbers are stored!

		public:
			// Vector Vector Operators
			vecNT &operator += (const vecNT &other) { execute<N - 1>(*this, other, opPlus);   return *this; }
			vecNT &operator -= (const vecNT &other) { execute<N - 1>(*this, other, opMinus);  return *this; }
			vecNT &operator *= (const vecNT &other) { execute<N - 1>(*this, other, opMulti);  return *this; }
			vecNT &operator /= (const vecNT &other) { execute<N - 1>(*this, other, opDivide); return *this; }
			
			// Vector Scaler Operators
			vecNT &operator += (T value) { execute<N - 1>(*this, value, opPlus);   return *this; }
			vecNT &operator -= (T value) { execute<N - 1>(*this, value, opMinus);  return *this; }
			vecNT &operator *= (T value) { execute<N - 1>(*this, value, opMulti);  return *this; }
			vecNT &operator /= (T value) { execute<N - 1>(*this, value, opDivide); return *this; }
			
			// Boolean Operators
			bool operator == (const vecNT &other) { return test(*this, other, opEquals); }
			bool operator != (const vecNT &other) { return !(*this == other); }
			
			// Array Accessor Operators
				  T &operator [] (size_t index)		  { return _vec[index]; }
			const T operator  [] (size_t index) const { return _vec[index]; }

			// Vector Related Functions
			inline T dot(const vecNT &other) { return sum<N - 1>(*this, other, opPlus, opMulti); }
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