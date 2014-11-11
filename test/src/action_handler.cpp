#include <mogui/action_handler.hpp>
#include <mogui/element.hpp>
#include <mogui/event.hpp>
#include <catch.hpp>

bool _action_handler_called = false;

void action_handler( mog::Element&, mog::Event& ) {
  _action_handler_called = true;
}

SCENARIO( "Construct ActionHandler." ) {
  GIVEN( "an element" ) {
    mog::Element element( "root" );
    
    WHEN( "default constructor is used" ) {
      mog::ActionHandler handler(
        &action_handler,
        element,
        mog::ActionHandler::Action::CLICK
      );

      THEN( "properties are set accordingly" ) {
        // Workaround for checking the callback.
        _action_handler_called = false;
        mog::Event fake_event( mog::Event::Action::MOUSE_MOVE );

        handler.get_callback()( element, fake_event );
        CHECK( _action_handler_called == true );

        CHECK( &handler.get_element() == &element );
        CHECK( handler.get_action() == mog::ActionHandler::Action::CLICK );
      }
    }
  }
}
