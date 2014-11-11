#include <mogui/event_propagator.hpp>
#include <mogui/element_selector.hpp>
#include <mogui/element.hpp>
#include <catch.hpp>

SCENARIO( "Construct EventPropagator." ) {
  WHEN( "the default constructor is used" ) {
    mog::EventPropagator gator;

    THEN( "the properties are set to their default values" ) {
      CHECK( gator.get_action_handler_count() == 0 );
    }
  }
}

SCENARIO( "Register EventPropagator action handlers." ) {
  GIVEN( "a propagator and some elements" ) {
    mog::Element first_element( "first" );
    mog::Element second_element( "second" );

    mog::EventPropagator gator;

    WHEN( "a handler for one element is registered" ) {
      /*
      gator.register_action_handler(
        []( mog::Element& ) {},
        first_element,
        mog::EventPropagator::Action::Click
      );
      */

      THEN( "the handler count is set accordingly" ) {
        /*
        CHECK( gator.get_action_handler_count() == 1 );
        */
      }

      THEN( "the action handler is set accordingly" ) {
        //const auto& handler = gator.get_action_handler( 0 );
      }
    }
  }
}
