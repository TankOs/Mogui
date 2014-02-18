#include <mogui/color.hpp>
#include <cassert>

namespace mog {

Color::Color() :
	_r( 0.0f ),
	_g( 0.0f ),
	_b( 0.0f ),
	_a( 1.0f )
{
}

Color::Color( float r, float g, float b ) :
	_r( r ),
	_g( g ),
	_b( b ),
	_a( 1.0f )
{
	assert( "Red must be clamped to [0..1]." && _r >= 0.0f && _r <= 1.0f );
	assert( "Green must be clamped to [0..1]." && _g >= 0.0f && _g <= 1.0f );
	assert( "Blue must be clamped to [0..1]." && _b >= 0.0f && _b <= 1.0f );
}

Color::Color( float r, float g, float b, float a ) :
	_r( r ),
	_g( g ),
	_b( b ),
	_a( a )
{
	assert( "Red must be clamped to [0..1]." && _r >= 0.0f && _r <= 1.0f );
	assert( "Green must be clamped to [0..1]." && _g >= 0.0f && _g <= 1.0f );
	assert( "Blue must be clamped to [0..1]." && _b >= 0.0f && _b <= 1.0f );
	assert( "Alpha must be clamped to [0..1]." && _a >= 0.0f && _a <= 1.0f );
}

float Color::r() const {
	return _r;
}

float Color::g() const {
	return _g;
}

float Color::b() const {
	return _b;
}

float Color::a() const {
	return _a;
}

void Color::r( float value ) {
	assert(
		"Value must be clamped to [0..1]." &&
		value >= 0.0f && value <= 1.0f
	);
	_r = value;
}

void Color::g( float value ) {
	assert(
		"Value must be clamped to [0..1]." &&
		value >= 0.0f && value <= 1.0f
	);
	_g = value;
}

void Color::b( float value ) {
	assert(
		"Value must be clamped to [0..1]." &&
		value >= 0.0f && value <= 1.0f
	);
	_b = value;
}

void Color::a( float value ) {
	assert(
		"Value must be clamped to [0..1]." &&
		value >= 0.0f && value <= 1.0f
	);
	_a = value;
}

void Color::rgb( float r, float g, float b ) {
	this->r( r );
	this->g( g );
	this->b( b );
}

void Color::rgba( float r, float g, float b, float a ) {
	this->r( r );
	this->g( g );
	this->b( b );
	this->a( a );
}

}

bool operator==( const mog::Color& lhs, const mog::Color& rhs ) {
	return (
		lhs.r() == rhs.r() &&
		lhs.g() == rhs.g() &&
		lhs.b() == rhs.b() &&
		lhs.a() == rhs.a()
	);
}

bool operator!=( const mog::Color& lhs, const mog::Color& rhs ) {
	return !(lhs == rhs);
}
