#pragma once

#include <mogui/vector2.hpp>

namespace mog {

template <class T>
class Rectangle {
	public:
		Rectangle();
		Rectangle( T x, T y, T width, T height );

		T left() const;
		T top() const;
		T width() const;
		T height() const;

		Vector2<T> location() const;
		Vector2<T> size() const;

		void left( T value );
		void top( T value );
		void width( T value );
		void height( T value );

		void location( Vector2<T> value );
		void size( Vector2<T> value );

	private:
		Vector2<T> _location;
		Vector2<T> _size;
};

}

template <class T>
bool operator==(
	const mog::Rectangle<T>& left,
	const mog::Rectangle<T>& right
);

template <class T>
bool operator!=(
	const mog::Rectangle<T>& left,
	const mog::Rectangle<T>& right
);

/** @cls mog::Rectangle
 * Rectangle
 */

/** @fn mog::Rectangle::Rectangle( x, y, width, height )
 * Undefined behaviour if width or height is less than 0.
 */

/** @fn mog::Rectangle::width( value )
 * Undefined behaviour if value is less than 0.
 */

/** @fn mog::Rectangle::height( value )
 * Undefined behaviour if value is less than 0.
 */

/** @fn mog::Rectangle::size( value )
 * Undefined behaviour if x or y of new value is less than 0.
 */

#include "rectangle.inl"
