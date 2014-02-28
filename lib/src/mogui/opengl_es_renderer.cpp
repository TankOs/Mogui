#include <mogui/opengl_es_renderer.hpp>
#include <cassert>

namespace mog {

void OpenGLESRenderer::drawable_count( std::size_t count ) {
	_drawables.resize( count );
}

std::size_t OpenGLESRenderer::drawable_count() const {
	return _drawables.size();
}

mog::Color OpenGLESRenderer::drawable_color( std::size_t index ) {
	assert( "Invalid drawable index." && index < _drawables.size() );
	return _drawables[index].color;
}

void OpenGLESRenderer::drawable_color( std::size_t index, mog::Color color ) {
	assert( "Invalid drawable index." && index < _drawables.size() );
	_drawables[index].color = color;
}

}
