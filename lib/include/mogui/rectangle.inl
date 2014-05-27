#include <cassert>

namespace mog {

template <class T>
Rectangle<T>::Rectangle() :
	_location( 0, 0 ),
	_size( 0, 0 )
{
}

template <class T>
Rectangle<T>::Rectangle( T x, T y, T width, T height ) :
	_location( x, y ),
	_size( width, height )
{
}

template <class T>
T Rectangle<T>::get_left() const {
	return _location.get_x();
}

template <class T>
T Rectangle<T>::get_top() const {
	return _location.get_y();
}

template <class T>
T Rectangle<T>::get_width() const {
	return _size.get_x();
}

template <class T>
T Rectangle<T>::get_height() const {
	return _size.get_y();
}

template <class T>
void Rectangle<T>::set_left( T value ) {
	_location.set_x( value );
}

template <class T>
void Rectangle<T>::set_top( T value ) {
	_location.set_y( value );
}

template <class T>
void Rectangle<T>::set_width( T value ) {
	assert( "With must be >= 0." && value >= 0 );
	_size.set_x( value );
}

template <class T>
void Rectangle<T>::set_height( T value ) {
	assert( "Height must be >= 0." && value >= 0 );
	_size.set_y( value );
}

template <class T>
void Rectangle<T>::set_location( Vector2<T> value ) {
	_location = value;
}

template <class T>
void Rectangle<T>::set_size( Vector2<T> value ) {
	assert( "Width must be >= 0." && value.get_x() >= 0 );
	assert( "Height must be >= 0." && value.get_y() >= 0 );
	_size = value;
}

template <class T>
Vector2<T> Rectangle<T>::get_location() const {
	return _location;
}

template <class T>
Vector2<T> Rectangle<T>::get_size() const {
	return _size;
}

}

template <class T>
bool operator==(
	const mog::Rectangle<T>& left,
	const mog::Rectangle<T>& right
) {
	return (
		left.get_left() == right.get_left() &&
		left.get_top() == right.get_top() &&
		left.get_width() == right.get_width() &&
		left.get_height() == right.get_height()
	);
}

template <class T>
bool operator!=(
	const mog::Rectangle<T>& left,
	const mog::Rectangle<T>& right
) {
	return !(left == right);
}
