#include <mogui/event_propagator.hpp>

namespace mog {

std::size_t EventPropagator::get_hook_count() const {
	return _hooks.size();
}

}
