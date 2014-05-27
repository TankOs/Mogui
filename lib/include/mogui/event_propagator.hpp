#pragma once

#include <vector>

namespace mog {

class EventPropagator {
	public:
		std::size_t get_hook_count() const;

	private:
		std::vector<char> _hooks;
};

}

/** @class EventPropagator
 * Propagate events to element hierarchies and hook actions.
 */
