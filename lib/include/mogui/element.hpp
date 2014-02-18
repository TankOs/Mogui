#pragma once

#include <mogui/rectangle.hpp>
#include <mogui/color.hpp>
#include <string>
#include <vector>
#include <memory>

namespace mog {

class Element {
	public:
		Element( const std::string& name );

		const std::string& name() const;

		std::size_t child_count() const;
		void append( std::unique_ptr<Element> element );
		Element& child( std::size_t index ) const;
		Element* parent() const;

		Rectangle<float> bounds() const;
		void bounds( Rectangle<float> new_bounds );

		Color background_color() const;
		void background_color( Color new_background_color );

	private:
		std::vector<std::unique_ptr<Element>> _children;
		std::string _name;
		Color _background_color;
		Rectangle<float> _bounds;
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

/** @fn mog::Element::child
 * Undefined behavior if index is invalid.
 * @see mog::Element::child_count
 */

/** @fn mog::Element::parent
 * Returns the parent element or nullptr if there's none.
 */
