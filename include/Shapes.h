#ifndef __MATHEMATICAL_SHAPES_H_
#define __MATHEMATICAL_SHAPES_H_

#include <cmath>
#include "Vector.h"

namespace mathematical {

	enum ShapeType {
		None,
		Point,
		Line,
		Rectangle,
		Cuboid,
		Circle,
		Sphere,
		Polygon,
	};

	template <typename T>
	union OmniShape
	{
		struct { T x, y; } line;
		struct { T width, height; } rectangle;
		struct { T radius; } circle;
		struct { T normx, normy, normz; } plane;
		struct { T width, height, depth; } cuboid;
		struct { T radius; } sphere;
	};

	template <typename T>
	struct Shape {
		ShapeType type;
		OmniShape shape;
	};

	//template <typename T>
	//struct Point {};

	//// 2D Shapes

	//template <typename T>
	//struct Line : public Shape<T> {
	//	templates::vec2T<T> direction;
	//};

	//template <typename T>
	//struct Rectangle : public Shape<T> {
	//	templates::vec2T<T> halfLength;
	//};

	//template <typename T>
	//struct Circle : public Shape<T> {
	//	T radius;
	//};

	//// 3D Shapes

	//template <typename T>
	//struct Plane : public Shape<T> {
	//	templates::vec3T<T> normal;
	//};

	//template <typename T>
	//struct Cuboid : public Shape<T> {
	//	templates::vec3T<T> halfLength;
	//};

	//template <typename T>
	//struct Sphere : public Shape<T> {
	//	T radius;
	//};
}

#endif