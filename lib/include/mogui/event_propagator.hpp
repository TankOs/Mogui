#pragma once

#include <mogui/element.hpp>
#include <vector>
#include <functional>
#include <cstdint>

namespace mog {

class EventPropagator {
	public:
		enum class Action : uint8_t {
			Click = 0
		};

		std::size_t get_action_handler_count() const;
		void register_action_handler(
			Action action,
			std::function<void( Element& )> callback
		);

	private:
		std::vector<char> _action_handlers;
};

}

/** @class EventPropagator
 * Propagate events to element hierarchies and register action handlers.
 */
