#include <mogui/action_handler.hpp>

namespace mog {

ActionHandler::ActionHandler(
  Callback callback,
  Element& element,
  Action action
) :
  _callback( callback ),
  _element( element ),
  _action( action )
{
}

ActionHandler::Callback ActionHandler::get_callback() const {
  return _callback;
}

Element& ActionHandler::get_element() const {
  return _element;
}

ActionHandler::Action ActionHandler::get_action() const {
  return _action;
}

}
