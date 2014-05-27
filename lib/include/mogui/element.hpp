#pragma once

#include <mogui/rectangle.hpp>
#include <mogui/color.hpp>
#include <string>
#include <vector>
#include <memory>

namespace mog {

class Event;

class Element {
	public:
		Element( const std::string& name );
		virtual ~Element() = default;

		const std::string& get_name() const;

		std::size_t get_child_count() const;
		void append( std::unique_ptr<Element> element );
		Element& get_child( std::size_t index ) const;
		Element* get_parent() const;

		Rectangle<float> get_area() const;
		void set_area( Rectangle<float> new_area );

		Color get_background_color() const;
		void set_background_color( Color new_background_color );

		void propagate( Event& event );

	private:
		virtual void on_event( Event& event );

		std::vector<std::unique_ptr<Element>> _children;
		std::string _name;
		Color _background_color;
		Rectangle<float> _area;
		Element* _parent;
};

}

/** @cls mog::Element
 * An element is a node in a tree of elements.
 *
 * One element can both be a parent and child node. It can contain zero to an
 * unlimited amount of child nodes.
 *
 * Every element must at least have a name, which does not have to be unique.
 *
 * Each element can, but is not required to, have an image and text attached.
 */

/** @fn mog::Element::append
 * Ownership of the element is taken.
 */

/** @fn mog::Element::get_child
 * Undefined behavior if index is invalid.
 * @see mog::Element::get_child_count
 */

/** @fn mog::Element::get_parent
 * Returns the parent element or nullptr if there's none.
 */
