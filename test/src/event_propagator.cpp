#include <mogui/event_propagator.hpp>
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

/*
SCENARIO( "Register actions." ) {
	GIVEN( "an element hierarchy and a propagator" ) {
		mog::Element root( "root" );
		auto& child0 = root.create_child( "child0" );
		auto& child1 = root.create_child( "child1" );
		auto& child0child0 = child0.create_child( "child0child0" );
		auto& child0child1 = child0.create_child( "child0child1" );
		auto& child1child0 = child1.create_child( "child1child0" );
		auto& child1child1 = child1.create_child( "child1child1" );

		mog::EventPropagator gator;

		WHEN( "an action handler is registered" ) {
			gator.register_action_handler(
				mog::EventPropagator::Action::Click,
				[]( mog::Element& ) {}
			);

			THEN( "the handler count is set accordingly" ) {
				CHECK( gator.get_action_handler_count() == 1 );
			}
		}
	}
}
*/
