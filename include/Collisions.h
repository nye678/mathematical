#ifndef __MATHEMATICAL_COLLISIONS_H_
#define __MATHEMATICAL_COLLISIONS_H_

#include "Shapes.h"
#include "RigidBody.h"

namespace mathematical {

	template <typename T>
	struct Contact {
		RigidBody<T> *body1, *body2;
		vec3T<T> contactNormal;
		vec3T<T> contactPoint;
		T penetration;
	};

	template <typename T, size_t M>
	struct CollisionData {
		const size_t NumContacts = M;
		Contact[M] contactData;
	};

	template <typename T>
	bool testCollisionPointPoint(RigidBody* body1, RigidBody* body2, CollisionData* collisionData)
	{
		
	}

	template <typename T>
	bool testCollisionPointLine(RigidBody* body1, RigidBody* body2, CollisionData* collisionData)
	{

	}

	template <typename T>
	bool testCollisionPointRectangle(RigidBody* body1, RigidBody* body2, CollisionData* collisionData)
	{

	}

	template <typename T>
	bool testCollisionPointCircle(RigidBody* body1, RigidBody* body2, CollisionData* collisionData)
	{

	}

	template <typename T>
	bool testCollisionPointPlane(RigidBody* body1, RigidBody* body2, CollisionData* collisionData)
	{

	}

	template <typename T>
	bool testCollisionPointCuboid(RigidBody* body1, RigidBody* body2, CollisionData* collisionData)
	{

	}

	template <typename T>
	bool testCollisionPointSphere(RigidBody* body1, RigidBody* body2, CollisionData* collisionData)
	{

	}
}

#endif