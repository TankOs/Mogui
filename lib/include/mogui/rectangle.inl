#include <cassert>

namespace mog {

template <class T>
Rectangle<T>::Rectangle() :
	x( 0 ),
	y( 0 ),
	width( 0 ),
	height( 0 )
{
}

template <class T>
Rectangle<T>::Rectangle( T x_, T y_, T width_, T height_ ) :
	x( x_ ),
	y( y_ ),
	width( width_ ),
	height( height_ )
{
}

template <class T>
Rectangle<T>::Rectangle( std::initializer_list<T> list ) :
	x( *(list.begin() + 0) ),
	y( *(list.begin() + 1) ),
	width( *(list.begin() + 2) ),
	height( *(list.begin() + 3) )
{
	assert( "4 values expected in initializer list." && list.size() == 4 );
}

}

template <class T>
bool operator==(
	const mog::Rectangle<T>& left,
	const mog::Rectangle<T>& right
) {
	return (
		left.x == right.x &&
		left.y == right.y &&
		left.width == right.width &&
		left.height == right.height
	);
}

template <class T>
bool operator!=(
	const mog::Rectangle<T>& left,
	const mog::Rectangle<T>& right
) {
	return !(left == right);
}
