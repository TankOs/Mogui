#include <mogui/event_propagator.hpp>

namespace mog {

std::size_t EventPropagator::get_action_handler_count() const {
	return _action_handlers.size();
}

void EventPropagator::register_action_handler(
	Action action,
	std::function<void( Element& )> callback
) {
}

}
