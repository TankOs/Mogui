#pragma once

#include <mogui/vector2.hpp>

namespace mog {

template <class T>
class Rectangle {
  public:
    Rectangle();
    Rectangle( T x, T y, T width, T height );

    T get_left() const;
    T get_top() const;
    T get_width() const;
    T get_height() const;

    Vector2<T> get_location() const;
    Vector2<T> get_size() const;

    void set_left( T value );
    void set_top( T value );
    void set_width( T value );
    void set_height( T value );

    void set_location( Vector2<T> value );
    void set_size( Vector2<T> value );

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

/** @fn mog::Rectangle::Rectangle
 * Undefined behaviour if width or height is less than 0.
 */

/** @fn mog::Rectangle::set_width
 * Undefined behaviour if value is less than 0.
 */

/** @fn mog::Rectangle::set_height
 * Undefined behaviour if value is less than 0.
 */

/** @fn mog::Rectangle::set_size
 * Undefined behaviour if x or y of new value is less than 0.
 */

#include "rectangle.inl"
