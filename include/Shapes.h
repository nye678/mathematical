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
	struct Shape {};

	template <typename T>
	struct Point : public Shape<T> {};

	// 2D Shapes

	template <typename T>
	struct Line : public Shape<T> {
		templates::vec2T<T> direction;
	};

	template <typename T>
	struct Rectangle : public Shape<T> {
		templates::vec2T<T> halfLength;
	};

	template <typename T>
	struct Circle : public Shape<T> {
		T radius;
	};

	// 3D Shapes

	template <typename T>
	struct Plane : public Shape<T> {
		templates::vec3T<T> normal;
	};

	template <typename T>
	struct Cuboid : public Shape<T> {
		templates::vec3T<T> halfLength;
	};

	template <typename T>
	struct Sphere : public Shape<T> {
		T radius;
	};
}

#endif