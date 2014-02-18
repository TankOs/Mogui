#pragma once

namespace mog {

class Color {
	public:
		Color();
		Color( float r, float g, float b );
		Color( float r, float g, float b, float a );

		float r() const;
		float g() const;
		float b() const;
		float a() const;

		void r( float value );
		void g( float value );
		void b( float value );
		void a( float value );

		void rgb( float r, float g, float b );
		void rgba( float r, float g, float b, float a );

	private:
		float _r;
		float _g;
		float _b;
		float _a;
};

}

bool operator==( const mog::Color& lhs, const mog::Color& rhs );
bool operator!=( const mog::Color& lhs, const mog::Color& rhs );

/** @class mog::Color
 * Color.
 *
 * The color values for red, green, blue and alpha have to be clamped to
 * [0..1]. If you try to set them to an invalid value, you will have to accept
 * undefined behavior.
 */

/** @fn mog::Color::r
 * Value must be clamped to [0..1], otherwise undefined behavior.
 */

/** @fn mog::Color::g
 * Value must be clamped to [0..1], otherwise undefined behavior.
 */

/** @fn mog::Color::b
 * Value must be clamped to [0..1], otherwise undefined behavior.
 */

/** @fn mog::Color::a
 * Value must be clamped to [0..1], otherwise undefined behavior.
 */

/** @fn mog::Color::rgb
 * Values must be clamped to [0..1], otherwise undefined behavior.
 */

/** @fn mog::Color::rgba
 * Values must be clamped to [0..1], otherwise undefined behavior.
 */
