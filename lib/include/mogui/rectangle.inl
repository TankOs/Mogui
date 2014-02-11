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

}
