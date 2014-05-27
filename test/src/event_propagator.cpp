#include <mogui/event_propagator.hpp>
#include <catch.hpp>

SCENARIO( "Construct EventPropagator." ) {
	WHEN( "the default constructor is used" ) {
		mog::EventPropagator gator;

		THEN( "the properties are set to their default values" ) {
			CHECK( gator.get_hook_count() == 0 );
		}
	}
}

/*
SCENARIO( "Propagate event using EventPropagators." ) {
	GIVEN( "an element hierarchy and a propagator" ) {
		Element root;
		
	}
}
*/
