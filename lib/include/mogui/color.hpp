#pragma once

namespace mog {

class Color {
	public:
		Color();
		Color( float r, float g, float b );
		Color( float r, float g, float b, float a );

		float get_r() const;
		float get_g() const;
		float get_b() const;
		float get_a() const;

		void set_r( float value );
		void set_g( float value );
		void set_b( float value );
		void set_a( float value );

		void set_rgb( float r, float g, float b );
		void set_rgba( float r, float g, float b, float a );

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

/** @fn mog::Color::set_r
 * Value must be clamped to [0..1], otherwise undefined behavior.
 */

/** @fn mog::Color::set_g
 * Value must be clamped to [0..1], otherwise undefined behavior.
 */

/** @fn mog::Color::set_b
 * Value must be clamped to [0..1], otherwise undefined behavior.
 */

/** @fn mog::Color::set_a
 * Value must be clamped to [0..1], otherwise undefined behavior.
 */

/** @fn mog::Color::set_rgb
 * Values must be clamped to [0..1], otherwise undefined behavior.
 */

/** @fn mog::Color::set_rgba
 * Values must be clamped to [0..1], otherwise undefined behavior.
 */
