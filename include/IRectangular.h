#ifndef __MATHEMATICAL_IRECTANGULAR_H_
#define __MATHEMATICAL_IRECTANGULAR_H_

namespace mathematical {
	namespace interfaces {

		// Rectangular Interface
		// Describes an object which is rectangular, or pretends to be rectangular.
		struct IRectangular {
			virtual int left()	 = 0;
			virtual int right()	 = 0;
			virtual int top()	 = 0;
			virtual int bottom() = 0;
			// Returns true if the bounds of each rectangle overlaps.
			virtual bool intersects(const IRectangular &) = 0;
			// Returns true if this rectangle completely contains the other.
			virtual bool contains(const IRectangular &) = 0;

		};

	}
}

#endif