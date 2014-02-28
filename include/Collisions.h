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
	bool testCollision(Point* point1, Point* point2, RigidBody* body1, RigidBody* body2, CollisionData* collisionData)
	{
		
	}

	template <typename T>
	bool testCollision(Point* point, Line* line, RigidBody* body1, RigidBody* body2, CollisionData* collisionData)
	{

	}

	template <typename T>
	bool testCollision(Point* point1, Rectangle* rect, RigidBody* body1, RigidBody* body2, CollisionData* collisionData)
	{

	}

	template <typename T>
	bool testCollision(Point* point1, Circle* circle, RigidBody* body1, RigidBody* body2, CollisionData* collisionData)
	{

	}

	template <typename T>
	bool testCollision(Point* point1, Plane* plane, RigidBody* body1, RigidBody* body2, CollisionData* collisionData)
	{

	}

	template <typename T>
	bool testCollision(Point* point1, Cuboid* cupoid, RigidBody* body1, RigidBody* body2, CollisionData* collisionData)
	{

	}

	template <typename T>
	bool testCollision(Point* point1, Sphere* sphere, RigidBody* body1, RigidBody* body2, CollisionData* collisionData)
	{

	}

	template <typename T>
	bool testCollision(RigidBody* body1, RigidBody* body2, CollisionData* collisionData)
	{
		return testCollision(rb1->shape, rb2->shape, body1, body2, c);
	}
}

#endif