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
T Rectangle<T>::left() const {
	return _location.x();
}

template <class T>
T Rectangle<T>::top() const {
	return _location.y();
}

template <class T>
T Rectangle<T>::width() const {
	return _size.x();
}

template <class T>
T Rectangle<T>::height() const {
	return _size.y();
}

template <class T>
void Rectangle<T>::left( T value ) {
	_location.x( value );
}

template <class T>
void Rectangle<T>::top( T value ) {
	_location.y( value );
}

template <class T>
void Rectangle<T>::width( T value ) {
	assert( "With must be >= 0." && value >= 0 );
	_size.x( value );
}

template <class T>
void Rectangle<T>::height( T value ) {
	assert( "Height must be >= 0." && value >= 0 );
	_size.y( value );
}

template <class T>
void Rectangle<T>::location( Vector2<T> value ) {
	_location = value;
}

template <class T>
void Rectangle<T>::size( Vector2<T> value ) {
	assert( "Width must be >= 0." && value.x() >= 0 );
	assert( "Height must be >= 0." && value.y() >= 0 );
	_size = value;
}

template <class T>
Vector2<T> Rectangle<T>::location() const {
	return _location;
}

template <class T>
Vector2<T> Rectangle<T>::size() const {
	return _size;
}

}

template <class T>
bool operator==(
	const mog::Rectangle<T>& left,
	const mog::Rectangle<T>& right
) {
	return (
		left.left() == right.left() &&
		left.top() == right.top() &&
		left.width() == right.width() &&
		left.height() == right.height()
	);
}

template <class T>
bool operator!=(
	const mog::Rectangle<T>& left,
	const mog::Rectangle<T>& right
) {
	return !(left == right);
}
