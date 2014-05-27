#pragma once

#include <mogui/color.hpp>
#include <vector>
#include <cstdint>

namespace mog {

class DrawableContainer {
	public:
		virtual ~DrawableContainer() = default;

		std::size_t get_drawable_count() const;
		std::size_t create_drawable();
		void reset();

		mog::Color get_drawable_color( std::size_t index ) const;
		void set_drawable_color( std::size_t index, mog::Color color );

	protected:
		enum class Change : uint8_t {
			COLOR = 0
		};

	private:
		struct Drawable {
			mog::Color color;
		};

		virtual void on_drawable_change( std::size_t index, Change what );

		std::vector<Drawable> _drawables;
};

}

/** @class mog::DrawableContainer
 * Holds drawables and provides an interface for changing them. Base class.
 */

/** @fn mog::DrawableContainer::create_drawable
 * Create a new drawable and return its handle.
 */
