#ifndef __MATHEMATICAL_GRID_H_
#define __MATHEMATICAL_GRID_H_

#include <vector>
#include "Shapes.h"

namespace mathematical {

	template <typename T>
	class IGrid {
	public:
		virtual void insert(T) = 0;

		std::vector<T> cell(size_t x, size_t y) { return _cell[x + y * W]; }

		template <typename... Ts>
		void foreachInCell(size_t x, size_t y, void(*gridAction)(T &, Ts... args))
		{
			for (auto obj : _cells[x + y * W])
			{
				gridAction(obj, args...);
			}
		}
	};

}

#endif