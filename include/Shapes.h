#ifndef __MATHEMATICAL_SHAPES_H_
#define __MATHEMATICAL_SHAPES_H_

namespace mathematical {

	template <typename T>
	struct Rectangle {
		T left, top, right, bottom;

		inline T width()  const	{ return right - left; }
		inline T height() const { return bottom - top; }

		bool intersects(const Rectangle &) const;
		bool contains(const Rectangle &, T margin = 0) const;

		Rectangle() : left(0), top(0), right(0), bottom(0) {}
		Rectangle(T left, T top, T right, T bottom) : left(left), top(top), right(right), bottom(bottom) {}
	};

	template <typename T>
	bool Rectangle<T>::intersects(const Rectangle &other)
	{
		if (left <= other.left)
			return (other.right - left <= width() + other.width() &&
					other.bottom - top <= height() + other.height())
		else
			return (right - other.left <= width() + other.width() &&
					bottom - other.top <= height() + other.height())
	}
}

#endif