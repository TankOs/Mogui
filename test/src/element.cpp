#include <mogui/element.hpp>
#include <catch.hpp>

SCENARIO( "Element can be constructed", "[mog::Element]" ) {
	WHEN( "name constructor is used" ) {
		mog::Element element( "test" );

		THEN( "name is set accordingly" ) {
			CHECK( element.get_name() == "test" );
		}
		THEN( "the element does not contain children" ) {
			CHECK( element.get_child_count() == 0 );
		}
		THEN( "the element does not have a parent set" ) {
			CHECK( element.get_parent() == nullptr );
		}
		THEN( "bounds are at 0, 0 and size is 0 * 0" ) {
			CHECK(
				element.get_bounds() ==
				mog::Rectangle<float>( 0.0f, 0.0f, 0.0f, 0.0f )
			);
		}
	}
}

SCENARIO( "Child elements can be added to an element", "[mog::Element]" ) {
	GIVEN( "an empty parent element" ) {
		mog::Element parent( "parent" );

		WHEN( "multiple elements are added" ) {
			auto child0 = std::unique_ptr<mog::Element>( new mog::Element( "0" ) );
			auto child1 = std::unique_ptr<mog::Element>( new mog::Element( "1" ) );
			auto child2 = std::unique_ptr<mog::Element>( new mog::Element( "2" ) );

			const auto* child0_ptr = child0.get();
			const auto* child1_ptr = child1.get();
			const auto* child2_ptr = child2.get();

			parent.add( std::move( child0 ) );
			parent.add( std::move( child1 ) );
			parent.add( std::move( child2 ) );

			THEN( "the child count equals the amount of added elements" ) {
				REQUIRE( parent.get_child_count() == 3 );
			}
			THEN( "the order of children is the same in which they were added" ) {
				CHECK( &parent.get_child( 0 ) == child0_ptr );
				CHECK( &parent.get_child( 1 ) == child1_ptr );
				CHECK( &parent.get_child( 2 ) == child2_ptr );
			}
			THEN( "the parent of each child is the actual parent" ) {
				CHECK( parent.get_child( 0 ).get_parent() == &parent );
				CHECK( parent.get_child( 1 ).get_parent() == &parent );
				CHECK( parent.get_child( 2 ).get_parent() == &parent );
			}
		}
	}
}

SCENARIO( "Element bounds can be changed.", "[mog::Element]" ) {
	GIVEN( "a default element" ) {
		mog::Element element( "default" );
		mog::Rectangle<float> new_bounds( 1.0f, 2.0f, 3.0f, 4.0f );

		REQUIRE( element.get_bounds() != new_bounds );

		WHEN( "bounds are changed" ) {
			element.set_bounds( new_bounds );

			THEN( "bounds are set accordingly" ) {
				CHECK( element.get_bounds() == new_bounds );
			}
		}
	}
}
