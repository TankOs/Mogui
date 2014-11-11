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

float Color::get_r() const {
  return _r;
}

float Color::get_g() const {
  return _g;
}

float Color::get_b() const {
  return _b;
}

float Color::get_a() const {
  return _a;
}

void Color::set_r( float value ) {
  assert(
    "Value must be clamped to [0..1]." &&
    value >= 0.0f && value <= 1.0f
  );
  _r = value;
}

void Color::set_g( float value ) {
  assert(
    "Value must be clamped to [0..1]." &&
    value >= 0.0f && value <= 1.0f
  );
  _g = value;
}

void Color::set_b( float value ) {
  assert(
    "Value must be clamped to [0..1]." &&
    value >= 0.0f && value <= 1.0f
  );
  _b = value;
}

void Color::set_a( float value ) {
  assert(
    "Value must be clamped to [0..1]." &&
    value >= 0.0f && value <= 1.0f
  );
  _a = value;
}

void Color::set_rgb( float r, float g, float b ) {
  _r = r;
  _g = g;
  _b = b;
}

void Color::set_rgba( float r, float g, float b, float a ) {
  _r = r;
  _g = g;
  _b = b;
  _a = a;
}

}

bool operator==( const mog::Color& lhs, const mog::Color& rhs ) {
  return (
    lhs.get_r() == rhs.get_r() &&
    lhs.get_g() == rhs.get_g() &&
    lhs.get_b() == rhs.get_b() &&
    lhs.get_a() == rhs.get_a()
  );
}

bool operator!=( const mog::Color& lhs, const mog::Color& rhs ) {
  return !(lhs == rhs);
}
