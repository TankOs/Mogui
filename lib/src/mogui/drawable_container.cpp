#include <mogui/drawable_container.hpp>
#include <cassert>

namespace mog {

std::size_t DrawableContainer::get_drawable_count() const {
	return _drawables.size();
}

std::size_t DrawableContainer::create_drawable() {
	_drawables.push_back( Drawable() );
	return _drawables.size() - 1;
}

void DrawableContainer::reset() {
	_drawables.clear();
}

mog::Color DrawableContainer::get_drawable_color( std::size_t index ) const {
	assert( "Invalid drawable index." && index < _drawables.size() );
	return _drawables[index].color;
}

void DrawableContainer::set_drawable_color( std::size_t index, mog::Color color ) {
	assert( "Invalid drawable index." && index < _drawables.size() );
	_drawables[index].color = color;

	on_drawable_change( 0, Change::COLOR );
}

void DrawableContainer::on_drawable_change( std::size_t, Change ) {
}

}
