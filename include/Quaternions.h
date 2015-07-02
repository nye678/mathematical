#ifndef __MATHEMATICAL_QUATERNIONS_H_
#define __MATEHMATICAL_QUATERNIONS_H_

#include <cstring>
#include "TemplateExpressions.h"

namespace mathematical {
	namespace templates {

		template <typename T>
		union quaternion {
			T _quat[4];
		public:
			struct { T w, x, y, z; };

			quaternion &operator += (const quaternion &other) { MetaExp<quaternion, T>::execute(*this, other, ArithmeticOps<T>::opPlus); return *this; }
			quaternion &operator -= (const quaternion &other) { MetaExp<quaternion, T>::execute(*this, other, ArithmeticOps<T>::opMinus); return *this; }
		
			quaternion &operator *= (const quaternion &other) {
				T tw = x * other.x - y * other.y - z * other.z - w * other.w;
				T tx = x * other.y + y * other.x + z * other.w - w * other.z;
				T ty = x * other.z - y * other.w + z * other.x + w * other.y;
				T tz = x * other.w + y * other.z - z * other.y + w * other.x;

				w = tw; x = tx; y = ty; z = tz;
			}

			quaternion() : w(0), x(0), y(0), z(0) {}
			quaternion(T angle, T x, T y, T z) : w(angle), x(x), y(y), z(z) {};
		};

	}

	typedef templates::quaternion<float> quatf;
	typedef templates::quaternion<double> quatd;
}

#endif