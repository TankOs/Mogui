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
T Vector2<T>::get_x() const {
  return _x;
}

template <class T>
T Vector2<T>::get_y() const {
  return _y;
}

template <class T>
void Vector2<T>::set_x( T value ) {
  _x = value;
}

template <class T>
void Vector2<T>::set_y( T value ) {
  _y = value;
}

}

template <class T>
mog::Vector2<T> operator+(
  const mog::Vector2<T>& left,
  const mog::Vector2<T>& right
) {
  return mog::Vector2<T>(
    left.get_x() + right.get_x(),
    left.get_y() + right.get_y()
  );
}

template <class T>
mog::Vector2<T>& operator+=(
  mog::Vector2<T>& left,
  const mog::Vector2<T>& right
) {
  left.set_x( left.get_x() + right.get_x() );
  left.set_y( left.get_y() + right.get_y() );

  return left;
}

template <class T>
mog::Vector2<T> operator-(
  const mog::Vector2<T>& left,
  const mog::Vector2<T>& right
) {
  return mog::Vector2<T>(
    left.get_x() - right.get_x(),
    left.get_y() - right.get_y()
  );
}

template <class T>
mog::Vector2<T>& operator-=(
  mog::Vector2<T>& left,
  const mog::Vector2<T>& right
) {
  left.set_x( left.get_x() - right.get_x() );
  left.set_y( left.get_y() - right.get_y() );

  return left;
}

template <class T>
bool operator==(
  const mog::Vector2<T>& left,
  const mog::Vector2<T>& right
) {
  return (
    left.get_x() == right.get_x() &&
    left.get_y() == right.get_y()
  );
}

template <class T>
bool operator!=(
  const mog::Vector2<T>& left,
  const mog::Vector2<T>& right
) {
  return !(left == right);
}
