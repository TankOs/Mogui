#pragma once

#include <mogui/renderer.hpp>
#include <mogui/color.hpp>
#include <vector>

namespace mog {

class OpenGLESRenderer : public Renderer {
	public:
		void drawable_count( std::size_t count ) override;
		std::size_t drawable_count() const override;

		mog::Color drawable_color( std::size_t index ) override;
		void drawable_color( std::size_t index, mog::Color color ) override;

	private:
		struct Drawable {
			mog::Color color;
		};

		std::vector<Drawable> _drawables;
};

}

/** @class mog::OpenGLESRenderer
 * Mogui renderer that's compatible to OpenGL ES 2.
 */
