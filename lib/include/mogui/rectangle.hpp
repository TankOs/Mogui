#pragma once

namespace mog {

template <class T>
class Rectangle {
	public:
		Rectangle();
		Rectangle( T x_, T y_, T width_, T height_ );

		T x;
		T y;
		T width;
		T height;

	private:
};

}

/** @cls mog::Rectangle
 * Simple rectangle data type.
 * The rectangle's components are not checked for validity, as this is a simple
 * data container. That means that width and height may contain weird values
 * below 0 if you set them explicitely.
 */

#include "rectangle.inl"
