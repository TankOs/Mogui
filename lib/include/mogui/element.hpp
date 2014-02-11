#pragma once

#include <mogui/rectangle.hpp>
#include <string>
#include <vector>
#include <memory>

namespace mog {

class Element {
	public:
		Element( const std::string& name );

		const std::string& get_name() const;

		std::size_t get_child_count() const;
		void add( std::unique_ptr<Element> element );
		Element& get_child( std::size_t index ) const;
		Element* get_parent() const;

		Rectangle<float> get_bounds() const;
		void set_bounds( Rectangle<float> bounds );

	private:
		std::vector<std::unique_ptr<Element>> m_children;
		std::string m_name;
		Rectangle<float> m_bounds;
		Element* m_parent;
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

/** @fn mog::Element::Element
 * Undefined behaviour if bounds' width or height is less than zero.
 */

/** @fn mog::Element::add
 * Ownership of the element is taken.
 */

/** @fn mog::Element::get_child
 * Undefined behavior if index is invalid.
 * @see mog::Element::get_child_count
 */

/** @fn mog::Element::get_parent
 * Returns the parent element or nullptr if there's none.
 */

/** @fn mog::Element::set_bounds
 * Undefined behaviour if bounds' width or height is less than zero.
 */
