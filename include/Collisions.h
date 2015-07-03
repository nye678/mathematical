#ifndef __MATHEMATICAL_COLLISIONS_H_
#define __MATHEMATICAL_COLLISIONS_H_

#include "Shapes.h"
#include "RigidBody.h"

namespace mathematical {

	template <typename T>
	struct Contact {
		RigidBody<T> *body1, *body2;
		templates::vec3T<T> contactNormal;
		templates::vec3T<T> contactPoint;
		T penetration;
	};

	template <typename T, size_t M>
	struct CollisionData {
		const size_t NumContacts = M;
		Contact contactData[M];
	};

	template <typename T>
	bool testCollisionPointPoint(RigidBody<T>* body1, RigidBody<T>* body2, CollisionData<T, 10>* collisionData)
	{
		Shape<T> &shape1 = body1->shape;
		T width = shape1.shape.rectangle.width; asdfkjds;flj
	}

	template <typename T>
	bool testCollisionPointLine(RigidBody<T>* body1, RigidBody<T>* body2, CollisionData<T, 10>* collisionData)
	{

	}

	template <typename T>
	bool testCollisionPointRectangle(RigidBody<T>* body1, RigidBody<T>* body2, CollisionData<T, 10>* collisionData)
	{

	}

	template <typename T>
	bool testCollisionPointCircle(RigidBody<T>* body1, RigidBody<T>* body2, CollisionData<T, 10>* collisionData)
	{

	}

	template <typename T>
	bool testCollisionPointPlane(RigidBody<T>* body1, RigidBody<T>* body2, CollisionData<T, 10>* collisionData)
	{

	}

	template <typename T>
	bool testCollisionPointCuboid(RigidBody<T>* body1, RigidBody<T>* body2, CollisionData<T, 10>* collisionData)
	{

	}

	template <typename T>
	bool testCollisionPointSphere(RigidBody<T>* body1, RigidBody<T>* body2, CollisionData<T, 10>* collisionData)
	{

	}

	template <>
	bool testCollisionPointPoint<float>(RigidBody<float>* body1, RigidBody<float>* body2, CollisionData<float, 10>* collisionData);
}

#endif