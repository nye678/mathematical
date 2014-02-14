#ifndef __MATHEMATICAL_QUATERNIONS_H_
#define __MATEHMATICAL_QUATERNIONS_H_

#include <cstring>
#include "TemplateExpressions.h"

namespace mathematical {
	namespace temps {

		template <typename T>
		class quaternion {
			T _quat[4];
		public:
			T w&, x&, y&, z&;

			quaternion &operator += (const quaternion &other) { MetaExp<quaternion, T>::execute(*this, other, ArithmeticOps<T>::opPlus); return *this; }
			quaternion &operator -= (const quaternion &other) { MetaExp<quaternion, T>::execute(*this, other, ArithmeticOps<T>::opMinus); return *this; }
		
			quaternion &operator *= (const quaternion &other) {
				T tw = x * other.x - y * other.y - z * other.z - w * other.w;
				T tx = x * other.y + y * other.x + z * other.w - w * other.z;
				T ty = x * other.z - y * other.w + z * other.x + w * other.y;
				T tz = x * other.w + y * other.z - z * other.y + w * other.x;

				w = tw; x = tx; y = ty; z = tz;
			}

			quaternion() : w(_quat[0]), x(_quat[1]), y(_quat[2]), z(_quat[3]) { memset(&_quat, 0, 4 * sizeof T); }
			quaternion(T angle, T x, T y, T z) : w(_quat[0]), x(_quat[1]), y(_quat[2]), z(_quat[3]) {
				this->w = angle;
				this->x = x;
				this->y = y;
				this->z = z;
			}
		};

	}

	typedef temps::quaternion<float> quatf;
	typedef temps::quaternion<double> quatd;
}

#endif