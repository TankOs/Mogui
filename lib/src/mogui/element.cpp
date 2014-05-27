#include <mogui/element.hpp>
#include <cassert>

namespace mog {

Element::Element( const std::string& name ) :
	_name( name ),
	_background_color( 1.0f, 1.0f, 1.0f, 1.0f ),
	_area( 0.0f, 0.0f, 0.0f, 0.0f ),
	_parent( nullptr )
{
}

const std::string& Element::get_name() const {
	return _name;
}

std::size_t Element::get_child_count() const {
	return _children.size();
}

void Element::append( std::unique_ptr<Element> element ) {
	assert( "Element is null." && element != nullptr );
	assert( "Element is already a child." && element->_parent == nullptr );

	element->_parent = this;
	_children.push_back( std::move( element ) );
}

Element& Element::get_child( std::size_t index ) const {
	assert( "Invalid child index." && index < get_child_count() );
	return *_children[index];
}

Element* Element::get_parent() const {
	return _parent;
}

Rectangle<float> Element::get_area() const {
	return _area;
}

void Element::set_area( Rectangle<float> new_area ) {
	_area = new_area;
}

Color Element::get_background_color() const {
	return _background_color;
}

void Element::set_background_color( Color new_background_color ) {
	_background_color = new_background_color;
}

void Element::on_event( Event& /*event*/ ) {
}

void Element::propagate( Event& event ) {
	on_event( event );

	for( auto& child : _children ) {
		child->propagate( event );
	}
}

}
