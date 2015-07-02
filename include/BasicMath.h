#ifndef __MATHEMATICAL_MATH_H_
#define __MATHEMATICAL_MATH_H_

#include <cmath>
#include <cstdint>

namespace mathematical {
	namespace templates {

		template <typename T>
		inline T piT() { return 0; }

		template <>
		inline float piT<float>() { return 3.14159265f; }

		template <>
		inline double piT<double>() { return 3.14159265; }

		template <typename T>
		inline T toDegreesT(T radians) { return radians * ((T)180.0f / piT<T>()); }

		template <typename T>
		inline T toRadiansT(T degrees) { return degrees * (piT<T>() / (T)180.0f); }

		template <typename T>
		inline T maxT(T a, T b) { return a > b ? a : b; }

		template <typename T>
		inline T minT(T a, T b) { return a < b ? a : b; }

		template <typename floatType, typename intType>
		inline floatType ceilT(floatType value) {
			intType n = (intType)(value + 1);
			return (floatType)((value <= n && n < value + 1) ? n : n - 1);
		}
	}

	typedef int32_t bool32_t;

	inline int32_t abs(int32_t i) { return i & 0x7FFFFFFF; }
	inline int64_t abs(int64_t i) { return i & 0x7FFFFFFFFFFFFFFF; }
	inline float abs(float f) {
		int32_t i = *(int32_t*)&f;
		i &= 0x7FFFFFFF;
		return *(float*)&i;
	}
	inline double abs(double d) {
		int64_t i = *(int64_t*)&d;
		i &= 0x7FFFFFFFFFFFFFFF;
		return *(double*)&i;
	}

	inline int32_t sign(int32_t i) { return (i & 0x80000000) | 1; }
	inline int64_t sign(int64_t i) { return (i & 0x8000000000000000) | 1; }
	inline float sign(float f) {
		int32_t i = *(int32_t*)&f;
		i = sign(i);
		return *(float*)&i;
	}
	inline double sign(double d) {
		int64_t i = *(int64_t*)&d;
		i = sign(i);
		return *(double*)&i;
	}

	inline float pi() { return templates::piT<float>(); }

	inline float toDegrees(float radians) { return templates::toDegreesT<float>(radians); }
	inline double toDegrees(double radians) { return templates::toDegreesT<double>(radians); }
	inline float toRadians(float degrees) { return templates::toRadiansT<float>(degrees); }
	inline double toRadians(double degrees) { return templates::toRadiansT<double>(degrees); }

	inline int32_t max(int32_t a, int32_t b) { return templates::maxT<int32_t>(a, b); }
	inline int64_t max(int64_t a, int64_t b) { return templates::maxT<int64_t>(a, b); }
	inline float max(float a, float b) { return templates::maxT<float>(a, b); }
	inline double max(double a, double b) { return templates::maxT<double>(a, b); }

	inline int32_t min(int32_t a, int32_t b) { return templates::minT<int32_t>(a, b); }
	inline int64_t min(int64_t a, int64_t b) { return templates::minT<int64_t>(a, b); }
	inline float min(float a, float b) { return templates::minT<float>(a, b); }
	inline double min(double a, double b) { return templates::minT<double>(a, b); }

	inline float floor(float f) { return (float)(int32_t)f; }
	inline double floor(double d) { return (float)(int64_t)d; }

	inline float ceil(float f) { return templates::ceilT<float, int32_t>(f); }
	inline double ceil(double d) { return templates::ceilT<double, int64_t>(d); }

	inline float round(float f) { return (float)(int32_t)((abs(f) + 0.5f) * sign(f)); }
	inline double round(double d) { return (double)(int64_t)((abs(d) + 0.5f) * sign(d)); }

	inline bool32_t almostEqual(float a, float b) { return abs(a - b) < 0.000001f; }
	inline bool32_t almostEqual(double a, double b) { return abs(a - b) < 0.000001; }
}

#endif