#pragma once

#include <mogui/color.hpp>
#include <mogui/vector2.hpp>

namespace mog {

class Renderer {
	public:
		virtual ~Renderer() = default;

		virtual void drawable_count( std::size_t count ) = 0;
		virtual std::size_t drawable_count() const = 0;

		virtual mog::Color drawable_color( std::size_t index ) = 0;
		virtual void drawable_color( std::size_t index, mog::Color color ) = 0;

	private:
};

}

/** @class mog::Renderer
 * Abstract base class for renderers.
 */
