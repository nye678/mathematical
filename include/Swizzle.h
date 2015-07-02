#ifndef __MATHEMATICAL_SWIZZLE_H_
#define __MATHEMATICAL_SWIZZLE_H_

#include "Vector.h"

namespace mathematical {
	namespace templates {
		template <typename T>
		class Swizzle {
		public:
			static inline vec2T<T> xx(const vec2T<T> &vec) { return vec2T<T>(vec.x, vec.x); }
			static inline vec2T<T> xx(const vec3T<T> &vec) { return vec2T<T>(vec.x, vec.x); }
			static inline vec2T<T> xx(const vec4T<T> &vec) { return vec2T<T>(vec.x, vec.x); }
			static inline vec2T<T> xy(const vec2T<T> &vec) { return vec2T<T>(vec.x, vec.y); }
			static inline vec2T<T> xy(const vec3T<T> &vec) { return vec2T<T>(vec.x, vec.y); }
			static inline vec2T<T> xy(const vec4T<T> &vec) { return vec2T<T>(vec.x, vec.y); }
			static inline vec2T<T> xz(const vec3T<T> &vec) { return vec2T<T>(vec.x, vec.z); }
			static inline vec2T<T> xz(const vec4T<T> &vec) { return vec2T<T>(vec.x, vec.z); }
			static inline vec2T<T> xw(const vec4T<T> &vec) { return vec2T<T>(vec.x, vec.w); }

			static inline vec2T<T> yx(const vec2T<T> &vec) { return vec2T<T>(vec.y, vec.x); }
			static inline vec2T<T> yx(const vec3T<T> &vec) { return vec2T<T>(vec.y, vec.x); }
			static inline vec2T<T> yx(const vec4T<T> &vec) { return vec2T<T>(vec.y, vec.x); }
			static inline vec2T<T> yy(const vec2T<T> &vec) { return vec2T<T>(vec.y, vec.y); }
			static inline vec2T<T> yy(const vec3T<T> &vec) { return vec2T<T>(vec.y, vec.y); }
			static inline vec2T<T> yy(const vec4T<T> &vec) { return vec2T<T>(vec.y, vec.y); }
			static inline vec2T<T> yz(const vec3T<T> &vec) { return vec2T<T>(vec.y, vec.z); }
			static inline vec2T<T> yz(const vec4T<T> &vec) { return vec2T<T>(vec.y, vec.z); }
			static inline vec2T<T> yw(const vec4T<T> &vec) { return vec2T<T>(vec.y, vec.w); }

			static inline vec2T<T> zx(const vec3T<T> &vec) { return vec2T<T>(vec.z, vec.x); }
			static inline vec2T<T> zx(const vec4T<T> &vec) { return vec2T<T>(vec.z, vec.x); }
			static inline vec2T<T> zy(const vec3T<T> &vec) { return vec2T<T>(vec.z, vec.y); }
			static inline vec2T<T> zy(const vec4T<T> &vec) { return vec2T<T>(vec.z, vec.y); }
			static inline vec2T<T> zz(const vec3T<T> &vec) { return vec2T<T>(vec.z, vec.z); }
			static inline vec2T<T> zz(const vec4T<T> &vec) { return vec2T<T>(vec.z, vec.z); }
			static inline vec2T<T> zw(const vec4T<T> &vec) { return vec2T<T>(vec.z, vec.w); }

			static inline vec2T<T> wx(const vec4T<T> &vec) { return vec2T<T>(vec.w, vec.x); }
			static inline vec2T<T> wy(const vec4T<T> &vec) { return vec2T<T>(vec.w, vec.y); }
			static inline vec2T<T> wz(const vec4T<T> &vec) { return vec2T<T>(vec.w, vec.z); }
			static inline vec2T<T> ww(const vec4T<T> &vec) { return vec2T<T>(vec.w, vec.w); }

			static inline vec3T<T> xxx(const vec3T<T> &vec) { return vec3T<T>(vec.x, vec.x, vec.x); }
			static inline vec3T<T> xxx(const vec4T<T> &vec) { return vec3T<T>(vec.x, vec.x, vec.x); }
			static inline vec3T<T> xxy(const vec3T<T> &vec) { return vec3T<T>(vec.x, vec.x, vec.y); }
			static inline vec3T<T> xxy(const vec4T<T> &vec) { return vec3T<T>(vec.x, vec.x, vec.y); }
			static inline vec3T<T> xxz(const vec3T<T> &vec) { return vec3T<T>(vec.x, vec.x, vec.z); }
			static inline vec3T<T> xxz(const vec4T<T> &vec) { return vec3T<T>(vec.x, vec.x, vec.z); }
			static inline vec3T<T> xxw(const vec4T<T> &vec) { return vec3T<T>(vec.x, vec.x, vec.w); }

			static inline vec3T<T> xyx(const vec3T<T> &vec) { return vec3T<T>(vec.x, vec.y, vec.x); }
			static inline vec3T<T> xyx(const vec4T<T> &vec) { return vec3T<T>(vec.x, vec.y, vec.x); }
			static inline vec3T<T> xyy(const vec3T<T> &vec) { return vec3T<T>(vec.x, vec.y, vec.y); }
			static inline vec3T<T> xyy(const vec4T<T> &vec) { return vec3T<T>(vec.x, vec.y, vec.y); }
			static inline vec3T<T> xyz(const vec3T<T> &vec) { return vec3T<T>(vec.x, vec.y, vec.z); }
			static inline vec3T<T> xyz(const vec4T<T> &vec) { return vec3T<T>(vec.x, vec.y, vec.z); }
			static inline vec3T<T> xyw(const vec4T<T> &vec) { return vec3T<T>(vec.x, vec.y, vec.w); }

			static inline vec3T<T> xzx(const vec3T<T> &vec) { return vec3T<T>(vec.x, vec.z, vec.x); }
			static inline vec3T<T> xzx(const vec4T<T> &vec) { return vec3T<T>(vec.x, vec.z, vec.x); }
			static inline vec3T<T> xzy(const vec3T<T> &vec) { return vec3T<T>(vec.x, vec.z, vec.y); }
			static inline vec3T<T> xzy(const vec4T<T> &vec) { return vec3T<T>(vec.x, vec.z, vec.y); }
			static inline vec3T<T> xzz(const vec3T<T> &vec) { return vec3T<T>(vec.x, vec.z, vec.z); }
			static inline vec3T<T> xzz(const vec4T<T> &vec) { return vec3T<T>(vec.x, vec.z, vec.z); }
			static inline vec3T<T> xzw(const vec4T<T> &vec) { return vec3T<T>(vec.x, vec.z, vec.w); }

			static inline vec3T<T> xwx(const vec4T<T> &vec) { return vec3T<T>(vec.x, vec.w, vec.x); }
			static inline vec3T<T> xwy(const vec4T<T> &vec) { return vec3T<T>(vec.x, vec.w, vec.y); }
			static inline vec3T<T> xwz(const vec4T<T> &vec) { return vec3T<T>(vec.x, vec.w, vec.z); }
			static inline vec3T<T> xww(const vec4T<T> &vec) { return vec3T<T>(vec.x, vec.w, vec.w); }

			static inline vec3T<T> yxx(const vec3T<T> &vec) { return vec3T<T>(vec.y, vec.x, vec.x); }
			static inline vec3T<T> yxx(const vec4T<T> &vec) { return vec3T<T>(vec.y, vec.x, vec.x); }
			static inline vec3T<T> yxy(const vec3T<T> &vec) { return vec3T<T>(vec.y, vec.x, vec.y); }
			static inline vec3T<T> yxy(const vec4T<T> &vec) { return vec3T<T>(vec.y, vec.x, vec.y); }
			static inline vec3T<T> yxz(const vec3T<T> &vec) { return vec3T<T>(vec.y, vec.x, vec.z); }
			static inline vec3T<T> yxz(const vec4T<T> &vec) { return vec3T<T>(vec.y, vec.x, vec.z); }
			static inline vec3T<T> yxw(const vec4T<T> &vec) { return vec3T<T>(vec.y, vec.x, vec.w); }
								   
			static inline vec3T<T> yyx(const vec3T<T> &vec) { return vec3T<T>(vec.y, vec.y, vec.x); }
			static inline vec3T<T> yyx(const vec4T<T> &vec) { return vec3T<T>(vec.y, vec.y, vec.x); }
			static inline vec3T<T> yyy(const vec3T<T> &vec) { return vec3T<T>(vec.y, vec.y, vec.y); }
			static inline vec3T<T> yyy(const vec4T<T> &vec) { return vec3T<T>(vec.y, vec.y, vec.y); }
			static inline vec3T<T> yyz(const vec3T<T> &vec) { return vec3T<T>(vec.y, vec.y, vec.z); }
			static inline vec3T<T> yyz(const vec4T<T> &vec) { return vec3T<T>(vec.y, vec.y, vec.z); }
			static inline vec3T<T> yyw(const vec4T<T> &vec) { return vec3T<T>(vec.y, vec.y, vec.w); }
								   
			static inline vec3T<T> yzx(const vec3T<T> &vec) { return vec3T<T>(vec.y, vec.z, vec.x); }
			static inline vec3T<T> yzx(const vec4T<T> &vec) { return vec3T<T>(vec.y, vec.z, vec.x); }
			static inline vec3T<T> yzy(const vec3T<T> &vec) { return vec3T<T>(vec.y, vec.z, vec.y); }
			static inline vec3T<T> yzy(const vec4T<T> &vec) { return vec3T<T>(vec.y, vec.z, vec.y); }
			static inline vec3T<T> yzz(const vec3T<T> &vec) { return vec3T<T>(vec.y, vec.z, vec.z); }
			static inline vec3T<T> yzz(const vec4T<T> &vec) { return vec3T<T>(vec.y, vec.z, vec.z); }
			static inline vec3T<T> yzw(const vec4T<T> &vec) { return vec3T<T>(vec.y, vec.z, vec.w); }
								   
			static inline vec3T<T> ywx(const vec4T<T> &vec) { return vec3T<T>(vec.y, vec.w, vec.x); }
			static inline vec3T<T> ywy(const vec4T<T> &vec) { return vec3T<T>(vec.y, vec.w, vec.y); }
			static inline vec3T<T> ywz(const vec4T<T> &vec) { return vec3T<T>(vec.y, vec.w, vec.z); }
			static inline vec3T<T> yww(const vec4T<T> &vec) { return vec3T<T>(vec.y, vec.w, vec.w); }

			static inline vec3T<T> zxx(const vec3T<T> &vec) { return vec3T<T>(vec.z, vec.x, vec.x); }
			static inline vec3T<T> zxx(const vec4T<T> &vec) { return vec3T<T>(vec.z, vec.x, vec.x); }
			static inline vec3T<T> zxy(const vec3T<T> &vec) { return vec3T<T>(vec.z, vec.x, vec.y); }
			static inline vec3T<T> zxy(const vec4T<T> &vec) { return vec3T<T>(vec.z, vec.x, vec.y); }
			static inline vec3T<T> zxz(const vec3T<T> &vec) { return vec3T<T>(vec.z, vec.x, vec.z); }
			static inline vec3T<T> zxz(const vec4T<T> &vec) { return vec3T<T>(vec.z, vec.x, vec.z); }
			static inline vec3T<T> zxw(const vec4T<T> &vec) { return vec3T<T>(vec.z, vec.x, vec.w); }

			static inline vec3T<T> zyx(const vec3T<T> &vec) { return vec3T<T>(vec.z, vec.y, vec.x); }
			static inline vec3T<T> zyx(const vec4T<T> &vec) { return vec3T<T>(vec.z, vec.y, vec.x); }
			static inline vec3T<T> zyy(const vec3T<T> &vec) { return vec3T<T>(vec.z, vec.y, vec.y); }
			static inline vec3T<T> zyy(const vec4T<T> &vec) { return vec3T<T>(vec.z, vec.y, vec.y); }
			static inline vec3T<T> zyz(const vec3T<T> &vec) { return vec3T<T>(vec.z, vec.y, vec.z); }
			static inline vec3T<T> zyz(const vec4T<T> &vec) { return vec3T<T>(vec.z, vec.y, vec.z); }
			static inline vec3T<T> zyw(const vec4T<T> &vec) { return vec3T<T>(vec.z, vec.y, vec.w); }

			static inline vec3T<T> zzx(const vec3T<T> &vec) { return vec3T<T>(vec.z, vec.z, vec.x); }
			static inline vec3T<T> zzx(const vec4T<T> &vec) { return vec3T<T>(vec.z, vec.z, vec.x); }
			static inline vec3T<T> zzy(const vec3T<T> &vec) { return vec3T<T>(vec.z, vec.z, vec.y); }
			static inline vec3T<T> zzy(const vec4T<T> &vec) { return vec3T<T>(vec.z, vec.z, vec.y); }
			static inline vec3T<T> zzz(const vec3T<T> &vec) { return vec3T<T>(vec.z, vec.z, vec.z); }
			static inline vec3T<T> zzz(const vec4T<T> &vec) { return vec3T<T>(vec.z, vec.z, vec.z); }
			static inline vec3T<T> zzw(const vec4T<T> &vec) { return vec3T<T>(vec.z, vec.z, vec.w); }

			static inline vec3T<T> zwx(const vec4T<T> &vec) { return vec3T<T>(vec.z, vec.w, vec.x); }
			static inline vec3T<T> zwy(const vec4T<T> &vec) { return vec3T<T>(vec.z, vec.w, vec.y); }
			static inline vec3T<T> zwz(const vec4T<T> &vec) { return vec3T<T>(vec.z, vec.w, vec.z); }
			static inline vec3T<T> zww(const vec4T<T> &vec) { return vec3T<T>(vec.z, vec.w, vec.w); }

			static inline vec3T<T> wxx(const vec4T<T> &vec) { return vec3T<T>(vec.w, vec.x, vec.x); }
			static inline vec3T<T> wxy(const vec4T<T> &vec) { return vec3T<T>(vec.w, vec.x, vec.y); }
			static inline vec3T<T> wxz(const vec4T<T> &vec) { return vec3T<T>(vec.w, vec.x, vec.z); }
			static inline vec3T<T> wxw(const vec4T<T> &vec) { return vec3T<T>(vec.w, vec.x, vec.w); }
								   												  
			static inline vec3T<T> wyx(const vec4T<T> &vec) { return vec3T<T>(vec.w, vec.y, vec.x); }
			static inline vec3T<T> wyy(const vec4T<T> &vec) { return vec3T<T>(vec.w, vec.y, vec.y); }
			static inline vec3T<T> wyz(const vec4T<T> &vec) { return vec3T<T>(vec.w, vec.y, vec.z); }
			static inline vec3T<T> wyw(const vec4T<T> &vec) { return vec3T<T>(vec.w, vec.y, vec.w); }
								   												  
			static inline vec3T<T> wzx(const vec4T<T> &vec) { return vec3T<T>(vec.w, vec.z, vec.x); }
			static inline vec3T<T> wzy(const vec4T<T> &vec) { return vec3T<T>(vec.w, vec.z, vec.y); }
			static inline vec3T<T> wzz(const vec4T<T> &vec) { return vec3T<T>(vec.w, vec.z, vec.z); }
			static inline vec3T<T> wzw(const vec4T<T> &vec) { return vec3T<T>(vec.w, vec.z, vec.w); }
								   												  
			static inline vec3T<T> wwx(const vec4T<T> &vec) { return vec3T<T>(vec.w, vec.w, vec.x); }
			static inline vec3T<T> wwy(const vec4T<T> &vec) { return vec3T<T>(vec.w, vec.w, vec.y); }
			static inline vec3T<T> wwz(const vec4T<T> &vec) { return vec3T<T>(vec.w, vec.w, vec.z); }
			static inline vec3T<T> www(const vec4T<T> &vec) { return vec3T<T>(vec.w, vec.w, vec.w); }

			static inline vec4T<T> xxxx(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.x, vec.x, vec.x); }
			static inline vec4T<T> xxxy(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.x, vec.x, vec.y); }
			static inline vec4T<T> xxxz(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.x, vec.x, vec.z); }
			static inline vec4T<T> xxxw(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.x, vec.x, vec.w); }

			static inline vec4T<T> xxyx(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.x, vec.y, vec.x); }
			static inline vec4T<T> xxyy(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.x, vec.y, vec.y); }
			static inline vec4T<T> xxyz(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.x, vec.y, vec.z); }
			static inline vec4T<T> xxyw(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.x, vec.y, vec.w); }

			static inline vec4T<T> xxzx(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.x, vec.x, vec.x); }
			static inline vec4T<T> xxzy(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.x, vec.x, vec.y); }
			static inline vec4T<T> xxzz(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.x, vec.x, vec.z); }
			static inline vec4T<T> xxzw(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.x, vec.x, vec.w); }

			static inline vec4T<T> xxwx(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.x, vec.x, vec.x); }
			static inline vec4T<T> xxwy(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.x, vec.x, vec.y); }
			static inline vec4T<T> xxwz(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.x, vec.x, vec.z); }
			static inline vec4T<T> xxww(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.x, vec.x, vec.w); }

			static inline vec4T<T> xyxx(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.y, vec.x, vec.x); }
			static inline vec4T<T> xyxy(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.y, vec.x, vec.y); }
			static inline vec4T<T> xyxz(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.y, vec.x, vec.z); }
			static inline vec4T<T> xyxw(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.y, vec.x, vec.w); }
																						  
			static inline vec4T<T> xyyx(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.y, vec.y, vec.x); }
			static inline vec4T<T> xyyy(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.y, vec.y, vec.y); }
			static inline vec4T<T> xyyz(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.y, vec.y, vec.z); }
			static inline vec4T<T> xyyw(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.y, vec.y, vec.w); }
																						  
			static inline vec4T<T> xyzx(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.y, vec.x, vec.x); }
			static inline vec4T<T> xyzy(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.y, vec.x, vec.y); }
			static inline vec4T<T> xyzz(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.y, vec.x, vec.z); }
			static inline vec4T<T> xyzw(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.y, vec.x, vec.w); }
																						  
			static inline vec4T<T> xywx(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.y, vec.x, vec.x); }
			static inline vec4T<T> xywy(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.y, vec.x, vec.y); }
			static inline vec4T<T> xywz(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.y, vec.x, vec.z); }
			static inline vec4T<T> xyww(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.y, vec.x, vec.w); }

			static inline vec4T<T> xzxx(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.z, vec.x, vec.x); }
			static inline vec4T<T> xzxy(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.z, vec.x, vec.y); }
			static inline vec4T<T> xzxz(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.z, vec.x, vec.z); }
			static inline vec4T<T> xzxw(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.z, vec.x, vec.w); }
																						  
			static inline vec4T<T> xzyx(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.z, vec.y, vec.x); }
			static inline vec4T<T> xzyy(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.z, vec.y, vec.y); }
			static inline vec4T<T> xzyz(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.z, vec.y, vec.z); }
			static inline vec4T<T> xzyw(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.z, vec.y, vec.w); }
																						  
			static inline vec4T<T> xzzx(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.z, vec.x, vec.x); }
			static inline vec4T<T> xzzy(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.z, vec.x, vec.y); }
			static inline vec4T<T> xzzz(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.z, vec.x, vec.z); }
			static inline vec4T<T> xzzw(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.z, vec.x, vec.w); }
																						  
			static inline vec4T<T> xzwx(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.z, vec.x, vec.x); }
			static inline vec4T<T> xzwy(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.z, vec.x, vec.y); }
			static inline vec4T<T> xzwz(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.z, vec.x, vec.z); }
			static inline vec4T<T> xzww(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.z, vec.x, vec.w); }

			static inline vec4T<T> xwxx(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.w, vec.x, vec.x); }
			static inline vec4T<T> xwxy(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.w, vec.x, vec.y); }
			static inline vec4T<T> xwxz(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.w, vec.x, vec.z); }
			static inline vec4T<T> xwxw(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.w, vec.x, vec.w); }
																						  
			static inline vec4T<T> xwyx(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.w, vec.y, vec.x); }
			static inline vec4T<T> xwyy(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.w, vec.y, vec.y); }
			static inline vec4T<T> xwyz(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.w, vec.y, vec.z); }
			static inline vec4T<T> xwyw(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.w, vec.y, vec.w); }
																						  
			static inline vec4T<T> xwzx(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.w, vec.x, vec.x); }
			static inline vec4T<T> xwzy(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.w, vec.x, vec.y); }
			static inline vec4T<T> xwzz(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.w, vec.x, vec.z); }
			static inline vec4T<T> xwzw(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.w, vec.x, vec.w); }
																						  
			static inline vec4T<T> xwwx(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.w, vec.x, vec.x); }
			static inline vec4T<T> xwwy(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.w, vec.x, vec.y); }
			static inline vec4T<T> xwwz(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.w, vec.x, vec.z); }
			static inline vec4T<T> xwww(const vec4T<T> &vec) { return vec4T<T>(vec.x, vec.w, vec.x, vec.w); }

			static inline vec4T<T> yxxx(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.x, vec.x, vec.x); }
			static inline vec4T<T> yxxy(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.x, vec.x, vec.y); }
			static inline vec4T<T> yxxz(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.x, vec.x, vec.z); }
			static inline vec4T<T> yxxw(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.x, vec.x, vec.w); }

			static inline vec4T<T> yxyx(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.x, vec.y, vec.x); }
			static inline vec4T<T> yxyy(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.x, vec.y, vec.y); }
			static inline vec4T<T> yxyz(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.x, vec.y, vec.z); }
			static inline vec4T<T> yxyw(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.x, vec.y, vec.w); }

			static inline vec4T<T> yxzx(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.x, vec.x, vec.x); }
			static inline vec4T<T> yxzy(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.x, vec.x, vec.y); }
			static inline vec4T<T> yxzz(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.x, vec.x, vec.z); }
			static inline vec4T<T> yxzw(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.x, vec.x, vec.w); }

			static inline vec4T<T> yxwx(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.x, vec.x, vec.x); }
			static inline vec4T<T> yxwy(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.x, vec.x, vec.y); }
			static inline vec4T<T> yxwz(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.x, vec.x, vec.z); }
			static inline vec4T<T> yxww(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.x, vec.x, vec.w); }

			static inline vec4T<T> yyxx(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.y, vec.x, vec.x); }
			static inline vec4T<T> yyxy(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.y, vec.x, vec.y); }
			static inline vec4T<T> yyxz(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.y, vec.x, vec.z); }
			static inline vec4T<T> yyxw(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.y, vec.x, vec.w); }

			static inline vec4T<T> yyyx(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.y, vec.y, vec.x); }
			static inline vec4T<T> yyyy(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.y, vec.y, vec.y); }
			static inline vec4T<T> yyyz(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.y, vec.y, vec.z); }
			static inline vec4T<T> yyyw(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.y, vec.y, vec.w); }

			static inline vec4T<T> yyzx(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.y, vec.x, vec.x); }
			static inline vec4T<T> yyzy(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.y, vec.x, vec.y); }
			static inline vec4T<T> yyzz(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.y, vec.x, vec.z); }
			static inline vec4T<T> yyzw(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.y, vec.x, vec.w); }

			static inline vec4T<T> yywx(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.y, vec.x, vec.x); }
			static inline vec4T<T> yywy(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.y, vec.x, vec.y); }
			static inline vec4T<T> yywz(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.y, vec.x, vec.z); }
			static inline vec4T<T> yyww(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.y, vec.x, vec.w); }

			static inline vec4T<T> yzxx(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.z, vec.x, vec.x); }
			static inline vec4T<T> yzxy(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.z, vec.x, vec.y); }
			static inline vec4T<T> yzxz(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.z, vec.x, vec.z); }
			static inline vec4T<T> yzxw(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.z, vec.x, vec.w); }

			static inline vec4T<T> yzyx(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.z, vec.y, vec.x); }
			static inline vec4T<T> yzyy(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.z, vec.y, vec.y); }
			static inline vec4T<T> yzyz(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.z, vec.y, vec.z); }
			static inline vec4T<T> yzyw(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.z, vec.y, vec.w); }

			static inline vec4T<T> yzzx(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.z, vec.x, vec.x); }
			static inline vec4T<T> yzzy(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.z, vec.x, vec.y); }
			static inline vec4T<T> yzzz(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.z, vec.x, vec.z); }
			static inline vec4T<T> yzzw(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.z, vec.x, vec.w); }

			static inline vec4T<T> yzwx(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.z, vec.x, vec.x); }
			static inline vec4T<T> yzwy(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.z, vec.x, vec.y); }
			static inline vec4T<T> yzwz(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.z, vec.x, vec.z); }
			static inline vec4T<T> yzww(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.z, vec.x, vec.w); }

			static inline vec4T<T> ywxx(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.w, vec.x, vec.x); }
			static inline vec4T<T> ywxy(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.w, vec.x, vec.y); }
			static inline vec4T<T> ywxz(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.w, vec.x, vec.z); }
			static inline vec4T<T> ywxw(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.w, vec.x, vec.w); }

			static inline vec4T<T> ywyx(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.w, vec.y, vec.x); }
			static inline vec4T<T> ywyy(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.w, vec.y, vec.y); }
			static inline vec4T<T> ywyz(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.w, vec.y, vec.z); }
			static inline vec4T<T> ywyw(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.w, vec.y, vec.w); }

			static inline vec4T<T> ywzx(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.w, vec.x, vec.x); }
			static inline vec4T<T> ywzy(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.w, vec.x, vec.y); }
			static inline vec4T<T> ywzz(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.w, vec.x, vec.z); }
			static inline vec4T<T> ywzw(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.w, vec.x, vec.w); }

			static inline vec4T<T> ywwx(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.w, vec.x, vec.x); }
			static inline vec4T<T> ywwy(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.w, vec.x, vec.y); }
			static inline vec4T<T> ywwz(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.w, vec.x, vec.z); }
			static inline vec4T<T> ywww(const vec4T<T> &vec) { return vec4T<T>(vec.y, vec.w, vec.x, vec.w); }

			static inline vec4T<T> zxxx(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.x, vec.x, vec.x); }
			static inline vec4T<T> zxxy(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.x, vec.x, vec.y); }
			static inline vec4T<T> zxxz(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.x, vec.x, vec.z); }
			static inline vec4T<T> zxxw(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.x, vec.x, vec.w); }

			static inline vec4T<T> zxyx(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.x, vec.y, vec.x); }
			static inline vec4T<T> zxyy(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.x, vec.y, vec.y); }
			static inline vec4T<T> zxyz(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.x, vec.y, vec.z); }
			static inline vec4T<T> zxyw(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.x, vec.y, vec.w); }

			static inline vec4T<T> zxzx(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.x, vec.x, vec.x); }
			static inline vec4T<T> zxzy(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.x, vec.x, vec.y); }
			static inline vec4T<T> zxzz(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.x, vec.x, vec.z); }
			static inline vec4T<T> zxzw(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.x, vec.x, vec.w); }

			static inline vec4T<T> zxwx(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.x, vec.x, vec.x); }
			static inline vec4T<T> zxwy(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.x, vec.x, vec.y); }
			static inline vec4T<T> zxwz(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.x, vec.x, vec.z); }
			static inline vec4T<T> zxww(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.x, vec.x, vec.w); }

			static inline vec4T<T> zyxx(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.y, vec.x, vec.x); }
			static inline vec4T<T> zyxy(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.y, vec.x, vec.y); }
			static inline vec4T<T> zyxz(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.y, vec.x, vec.z); }
			static inline vec4T<T> zyxw(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.y, vec.x, vec.w); }

			static inline vec4T<T> zyyx(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.y, vec.y, vec.x); }
			static inline vec4T<T> zyyy(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.y, vec.y, vec.y); }
			static inline vec4T<T> zyyz(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.y, vec.y, vec.z); }
			static inline vec4T<T> zyyw(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.y, vec.y, vec.w); }

			static inline vec4T<T> zyzx(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.y, vec.x, vec.x); }
			static inline vec4T<T> zyzy(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.y, vec.x, vec.y); }
			static inline vec4T<T> zyzz(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.y, vec.x, vec.z); }
			static inline vec4T<T> zyzw(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.y, vec.x, vec.w); }

			static inline vec4T<T> zywx(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.y, vec.x, vec.x); }
			static inline vec4T<T> zywy(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.y, vec.x, vec.y); }
			static inline vec4T<T> zywz(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.y, vec.x, vec.z); }
			static inline vec4T<T> zyww(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.y, vec.x, vec.w); }

			static inline vec4T<T> zzxx(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.z, vec.x, vec.x); }
			static inline vec4T<T> zzxy(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.z, vec.x, vec.y); }
			static inline vec4T<T> zzxz(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.z, vec.x, vec.z); }
			static inline vec4T<T> zzxw(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.z, vec.x, vec.w); }

			static inline vec4T<T> zzyx(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.z, vec.y, vec.x); }
			static inline vec4T<T> zzyy(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.z, vec.y, vec.y); }
			static inline vec4T<T> zzyz(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.z, vec.y, vec.z); }
			static inline vec4T<T> zzyw(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.z, vec.y, vec.w); }

			static inline vec4T<T> zzzx(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.z, vec.x, vec.x); }
			static inline vec4T<T> zzzy(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.z, vec.x, vec.y); }
			static inline vec4T<T> zzzz(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.z, vec.x, vec.z); }
			static inline vec4T<T> zzzw(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.z, vec.x, vec.w); }

			static inline vec4T<T> zzwx(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.z, vec.x, vec.x); }
			static inline vec4T<T> zzwy(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.z, vec.x, vec.y); }
			static inline vec4T<T> zzwz(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.z, vec.x, vec.z); }
			static inline vec4T<T> zzww(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.z, vec.x, vec.w); }

			static inline vec4T<T> zwxx(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.w, vec.x, vec.x); }
			static inline vec4T<T> zwxy(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.w, vec.x, vec.y); }
			static inline vec4T<T> zwxz(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.w, vec.x, vec.z); }
			static inline vec4T<T> zwxw(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.w, vec.x, vec.w); }

			static inline vec4T<T> zwyx(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.w, vec.y, vec.x); }
			static inline vec4T<T> zwyy(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.w, vec.y, vec.y); }
			static inline vec4T<T> zwyz(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.w, vec.y, vec.z); }
			static inline vec4T<T> zwyw(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.w, vec.y, vec.w); }

			static inline vec4T<T> zwzx(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.w, vec.x, vec.x); }
			static inline vec4T<T> zwzy(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.w, vec.x, vec.y); }
			static inline vec4T<T> zwzz(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.w, vec.x, vec.z); }
			static inline vec4T<T> zwzw(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.w, vec.x, vec.w); }

			static inline vec4T<T> zwwx(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.w, vec.x, vec.x); }
			static inline vec4T<T> zwwy(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.w, vec.x, vec.y); }
			static inline vec4T<T> zwwz(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.w, vec.x, vec.z); }
			static inline vec4T<T> zwww(const vec4T<T> &vec) { return vec4T<T>(vec.z, vec.w, vec.x, vec.w); }

			static inline vec4T<T> wxxx(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.x, vec.x, vec.x); }
			static inline vec4T<T> wxxy(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.x, vec.x, vec.y); }
			static inline vec4T<T> wxxz(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.x, vec.x, vec.z); }
			static inline vec4T<T> wxxw(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.x, vec.x, vec.w); }

			static inline vec4T<T> wxyx(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.x, vec.y, vec.x); }
			static inline vec4T<T> wxyy(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.x, vec.y, vec.y); }
			static inline vec4T<T> wxyz(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.x, vec.y, vec.z); }
			static inline vec4T<T> wxyw(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.x, vec.y, vec.w); }

			static inline vec4T<T> wxzx(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.x, vec.x, vec.x); }
			static inline vec4T<T> wxzy(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.x, vec.x, vec.y); }
			static inline vec4T<T> wxzz(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.x, vec.x, vec.z); }
			static inline vec4T<T> wxzw(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.x, vec.x, vec.w); }

			static inline vec4T<T> wxwx(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.x, vec.x, vec.x); }
			static inline vec4T<T> wxwy(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.x, vec.x, vec.y); }
			static inline vec4T<T> wxwz(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.x, vec.x, vec.z); }
			static inline vec4T<T> wxww(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.x, vec.x, vec.w); }

			static inline vec4T<T> wyxx(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.y, vec.x, vec.x); }
			static inline vec4T<T> wyxy(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.y, vec.x, vec.y); }
			static inline vec4T<T> wyxz(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.y, vec.x, vec.z); }
			static inline vec4T<T> wyxw(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.y, vec.x, vec.w); }

			static inline vec4T<T> wyyx(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.y, vec.y, vec.x); }
			static inline vec4T<T> wyyy(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.y, vec.y, vec.y); }
			static inline vec4T<T> wyyz(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.y, vec.y, vec.z); }
			static inline vec4T<T> wyyw(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.y, vec.y, vec.w); }

			static inline vec4T<T> wyzx(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.y, vec.x, vec.x); }
			static inline vec4T<T> wyzy(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.y, vec.x, vec.y); }
			static inline vec4T<T> wyzz(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.y, vec.x, vec.z); }
			static inline vec4T<T> wyzw(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.y, vec.x, vec.w); }

			static inline vec4T<T> wywx(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.y, vec.x, vec.x); }
			static inline vec4T<T> wywy(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.y, vec.x, vec.y); }
			static inline vec4T<T> wywz(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.y, vec.x, vec.z); }
			static inline vec4T<T> wyww(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.y, vec.x, vec.w); }

			static inline vec4T<T> wzxx(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.z, vec.x, vec.x); }
			static inline vec4T<T> wzxy(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.z, vec.x, vec.y); }
			static inline vec4T<T> wzxz(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.z, vec.x, vec.z); }
			static inline vec4T<T> wzxw(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.z, vec.x, vec.w); }

			static inline vec4T<T> wzyx(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.z, vec.y, vec.x); }
			static inline vec4T<T> wzyy(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.z, vec.y, vec.y); }
			static inline vec4T<T> wzyz(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.z, vec.y, vec.z); }
			static inline vec4T<T> wzyw(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.z, vec.y, vec.w); }

			static inline vec4T<T> wzzx(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.z, vec.x, vec.x); }
			static inline vec4T<T> wzzy(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.z, vec.x, vec.y); }
			static inline vec4T<T> wzzz(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.z, vec.x, vec.z); }
			static inline vec4T<T> wzzw(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.z, vec.x, vec.w); }

			static inline vec4T<T> wzwx(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.z, vec.x, vec.x); }
			static inline vec4T<T> wzwy(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.z, vec.x, vec.y); }
			static inline vec4T<T> wzwz(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.z, vec.x, vec.z); }
			static inline vec4T<T> wzww(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.z, vec.x, vec.w); }

			static inline vec4T<T> wwxx(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.w, vec.x, vec.x); }
			static inline vec4T<T> wwxy(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.w, vec.x, vec.y); }
			static inline vec4T<T> wwxz(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.w, vec.x, vec.z); }
			static inline vec4T<T> wwxw(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.w, vec.x, vec.w); }

			static inline vec4T<T> wwyx(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.w, vec.y, vec.x); }
			static inline vec4T<T> wwyy(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.w, vec.y, vec.y); }
			static inline vec4T<T> wwyz(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.w, vec.y, vec.z); }
			static inline vec4T<T> wwyw(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.w, vec.y, vec.w); }

			static inline vec4T<T> wwzx(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.w, vec.x, vec.x); }
			static inline vec4T<T> wwzy(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.w, vec.x, vec.y); }
			static inline vec4T<T> wwzz(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.w, vec.x, vec.z); }
			static inline vec4T<T> wwzw(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.w, vec.x, vec.w); }

			static inline vec4T<T> wwwx(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.w, vec.x, vec.x); }
			static inline vec4T<T> wwwy(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.w, vec.x, vec.y); }
			static inline vec4T<T> wwwz(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.w, vec.x, vec.z); }
			static inline vec4T<T> wwww(const vec4T<T> &vec) { return vec4T<T>(vec.w, vec.w, vec.x, vec.w); }
		};
	}

	typedef templates::Swizzle<float> Swizzlef;
	typedef templates::Swizzle<double> Swizzled;
}

#endif