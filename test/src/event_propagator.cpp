#include <mogui/event_propagator.hpp>
#include <catch.hpp>

using mog::EventPropagator;

SCENARIO( "Construct EventPropagators." ) {
	WHEN( "the default constructor is used" ) {
		EventPropagator gator;

		THEN( "the properties are set to their default values" ) {
			CHECK( gator.get_hook_count() == 0 );
		}
	}
}

/*
SCENARIO( "EventPropagators can propagate events." ) {
	GIVEN( "an element hierarchy and a propagator" ) {
		
	}
}
*/
