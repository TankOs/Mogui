#include <mogui/element.hpp>
#include <cassert>

namespace mog {

Element::Element( const std::string& name ) :
	_name( name ),
	_background_color( 1.0f, 1.0f, 1.0f, 1.0f ),
	_bounds( 0.0f, 0.0f, 0.0f, 0.0f ),
	_parent( nullptr )
{
}

const std::string& Element::name() const {
	return _name;
}

std::size_t Element::child_count() const {
	return _children.size();
}

void Element::append( std::unique_ptr<Element> element ) {
	assert( "Element is null." && element != nullptr );
	assert( "Element is already a child." && element->_parent == nullptr );

	element->_parent = this;
	_children.push_back( std::move( element ) );
}

Element& Element::child( std::size_t index ) const {
	assert( "Invalid child index." && index < child_count() );
	return *_children[index];
}

Element* Element::parent() const {
	return _parent;
}

Rectangle<float> Element::bounds() const {
	return _bounds;
}

void Element::bounds( Rectangle<float> new_bounds ) {
	_bounds = new_bounds;
}

Color Element::background_color() const {
	return _background_color;
}

void Element::background_color( Color new_background_color ) {
	_background_color = new_background_color;
}

}
