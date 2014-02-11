#include <mogui/element.hpp>
#include <cassert>

namespace mog {

Element::Element( const std::string& name ) :
	m_name( name ),
	m_bounds( 0.0f, 0.0f, 0.0f, 0.0f ),
	m_parent( nullptr )
{
	assert(
		"Invalid bounds width/height." && (
			m_bounds.width >= 0 || m_bounds.height >= 0
		)
	);
}

const std::string& Element::get_name() const {
	return m_name;
}

std::size_t Element::get_child_count() const {
	return m_children.size();
}

void Element::add( std::unique_ptr<Element> element ) {
	assert( "Element is null." && element != nullptr );
	assert( "Element is already a child." && element->m_parent == nullptr );

	element->m_parent = this;
	m_children.push_back( std::move( element ) );
}

Element& Element::get_child( std::size_t index ) const {
	assert( "Invalid child index." && index < get_child_count() );
	return *m_children[index];
}

Element* Element::get_parent() const {
	return m_parent;
}

Rectangle<float> Element::get_bounds() const {
	return m_bounds;
}

void Element::set_bounds( Rectangle<float> bounds ) {
	assert(
		"Invalid bounds width/height." && (
			bounds.width >= 0 || bounds.height >= 0
		)
	);

	m_bounds = bounds;
}

}
