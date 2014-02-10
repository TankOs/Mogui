#pragma once

#include <cstdint>

namespace mog {

template <class T>
class Vector2 {
	public:
		Vector2();
		Vector2( T x_, T y_ );

		T x;
		T y;

	private:
};

typedef Vector2<float> Vector2f;
typedef Vector2<int32_t> Vector2i32;
typedef Vector2<int16_t> Vector2i16;
typedef Vector2<int8_t> Vector2i8;
typedef Vector2<uint32_t> Vector2u32;
typedef Vector2<uint16_t> Vector2u16;
typedef Vector2<uint8_t> Vector2u8;
}

template <class T>
mog::Vector2<T> operator+(
	const mog::Vector2<T>& left,
	const mog::Vector2<T>& right
);

template <class T>
mog::Vector2<T>& operator+=(
	mog::Vector2<T>& left,
	const mog::Vector2<T>& right
);

template <class T>
mog::Vector2<T> operator-(
	const mog::Vector2<T>& left,
	const mog::Vector2<T>& right
);

template <class T>
mog::Vector2<T>& operator-=(
	mog::Vector2<T>& left,
	const mog::Vector2<T>& right
);

#include "vector2.inl"
