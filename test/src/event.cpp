#include <mogui/event.hpp>
#include <catch.hpp>

using mog::Event;

SCENARIO( "Events can be constructed." ) {
	WHEN( "a mouse move event is constructed" ) {
		Event event( Event::Action::MOUSE_MOVE );

		THEN( "all properties are set to their defaults" ) {
			CHECK( event.action() == Event::Action::MOUSE_MOVE );
			CHECK( event.sender() == nullptr );
			CHECK( event.mouse_position() == mog::Vector2<uint16_t>( 0, 0 ) );
		}
	}

	WHEN( "a mouse button press event is constructed" ) {
		Event event( Event::Action::MOUSE_BUTTON_PRESS );

		THEN( "all properties are set to their defaults" ) {
			CHECK( event.action() == Event::Action::MOUSE_BUTTON_PRESS );
			CHECK( event.sender() == nullptr );
			CHECK( event.mouse_position() == mog::Vector2<uint16_t>( 0, 0 ) );
			CHECK( event.mouse_button() == Event::MouseButton::LEFT );
		}
	}

	WHEN( "a mouse button release event is constructed" ) {
		Event event( Event::Action::MOUSE_BUTTON_RELEASE );

		THEN( "all properties are set to their defaults" ) {
			CHECK( event.action() == Event::Action::MOUSE_BUTTON_RELEASE );
			CHECK( event.sender() == nullptr );
			CHECK( event.mouse_position() == mog::Vector2<uint16_t>( 0, 0 ) );
			CHECK( event.mouse_button() == Event::MouseButton::LEFT );
		}
	}

	WHEN( "a key press event is constructed" ) {
		Event event( Event::Action::KEY_PRESS );

		THEN( "all properties are set to their defaults" ) {
			CHECK( event.action() == Event::Action::KEY_PRESS );
			CHECK( event.sender() == nullptr );
			CHECK( event.key() == 0 );
		}
	}

	WHEN( "a key release event is constructed" ) {
		Event event( Event::Action::KEY_RELEASE );

		THEN( "all properties are set to their defaults" ) {
			CHECK( event.action() == Event::Action::KEY_RELEASE );
			CHECK( event.sender() == nullptr );
			CHECK( event.key() == 0 );
		}
	}
}
