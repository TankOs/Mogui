#pragma once

#include <functional>
#include <cstdint>

namespace mog {

class Element;
class Event;

class ActionHandler {
  public:
    typedef std::function<void( mog::Element&, mog::Event& )> Callback;

    enum class Action : uint8_t {
      CLICK = 0
    };

    ActionHandler( Callback callback, Element& element, Action action );

    Callback get_callback() const;
    Element& get_element() const;
    Action get_action() const;

  private:
    Callback _callback;
    Element& _element;
    Action _action;
};

}

/** @class mog::ActionHandler
 * Action handler consisting of callback, target element and action type.
 */
