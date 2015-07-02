#ifndef __MATHEMATICAL_RIGIDBODY_H_
#define __MATHEMATICAL_RIGIDBODY_H_

#include "Shapes.h"

namespace mathematical {

	template <typename T>
	struct RigidBody {
		Shape<T>* shape;
		vec3T<T> position;
	};

}

#endif