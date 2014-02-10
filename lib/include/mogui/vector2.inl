namespace mog {

template <class T>
Vector2<T>::Vector2() :
	x( 0 ),
	y( 0 )
{
}

template <class T>
Vector2<T>::Vector2( T x_, T y_ ) :
	x( x_ ),
	y( y_ )
{
}

}

template <class T>
mog::Vector2<T> operator+(
	const mog::Vector2<T>& left,
	const mog::Vector2<T>& right
) {
	return mog::Vector2<T>(
		left.x + right.x,
		left.y + right.y
	);
}

template <class T>
mog::Vector2<T>& operator+=(
	mog::Vector2<T>& left,
	const mog::Vector2<T>& right
) {
	left.x += right.x;
	left.y += right.y;

	return left;
}

template <class T>
mog::Vector2<T> operator-(
	const mog::Vector2<T>& left,
	const mog::Vector2<T>& right
) {
	return mog::Vector2<T>(
		left.x - right.x,
		left.y - right.y
	);
}

template <class T>
mog::Vector2<T>& operator-=(
	mog::Vector2<T>& left,
	const mog::Vector2<T>& right
) {
	left.x -= right.x;
	left.y -= right.y;

	return left;
}

