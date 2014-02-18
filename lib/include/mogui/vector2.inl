namespace mog {

template <class T>
Vector2<T>::Vector2() :
	_x( 0 ),
	_y( 0 )
{
}

template <class T>
Vector2<T>::Vector2( T x, T y ) :
	_x( x ),
	_y( y )
{
}

template <class T>
T Vector2<T>::x() const {
	return _x;
}

template <class T>
T Vector2<T>::y() const {
	return _y;
}

template <class T>
void Vector2<T>::x( T value ) {
	_x = value;
}

template <class T>
void Vector2<T>::y( T value ) {
	_y = value;
}

}

template <class T>
mog::Vector2<T> operator+(
	const mog::Vector2<T>& left,
	const mog::Vector2<T>& right
) {
	return mog::Vector2<T>(
		left.x() + right.x(),
		left.y() + right.y()
	);
}

template <class T>
mog::Vector2<T>& operator+=(
	mog::Vector2<T>& left,
	const mog::Vector2<T>& right
) {
	left.x( left.x() + right.x() );
	left.y( left.y() + right.y() );

	return left;
}

template <class T>
mog::Vector2<T> operator-(
	const mog::Vector2<T>& left,
	const mog::Vector2<T>& right
) {
	return mog::Vector2<T>(
		left.x() - right.x(),
		left.y() - right.y()
	);
}

template <class T>
mog::Vector2<T>& operator-=(
	mog::Vector2<T>& left,
	const mog::Vector2<T>& right
) {
	left.x( left.x() - right.x() );
	left.y( left.y() - right.y() );

	return left;
}

template <class T>
bool operator==(
	const mog::Vector2<T>& left,
	const mog::Vector2<T>& right
) {
	return (
		left.x() == right.x() &&
		left.y() == right.y()
	);
}

template <class T>
bool operator!=(
	const mog::Vector2<T>& left,
	const mog::Vector2<T>& right
) {
	return !(left == right);
}
