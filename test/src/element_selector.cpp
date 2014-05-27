#include <mogui/element_selector.hpp>
#include <catch.hpp>

SCENARIO( "Construct ElementSelector." ) {
	WHEN( "default constructor is used" ) {
		mog::ElementSelector selector;

		THEN( "properties are set to their default values" ) {
			CHECK( selector.get_name() == "" );
		}
	}
}

SCENARIO( "Change ElementSelector properties." ) {
	GIVEN( "an ElementSelector" ) {
		mog::ElementSelector selector;

		WHEN( "name is changed" ) {
			REQUIRE( selector.get_name() != "foobar" );

			selector.set_name( "foobar" );

			THEN( "name is set accordingly" ) {
				CHECK( selector.get_name() == "foobar" );
			}
		}
	}
}
