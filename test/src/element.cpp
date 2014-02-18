#include <mogui/element.hpp>
#include <catch.hpp>

SCENARIO( "Element can be constructed", "[mog::Element]" ) {
	WHEN( "name constructor is used" ) {
		mog::Element element( "test" );

		THEN( "name is set accordingly" ) {
			CHECK( element.name() == "test" );
		}
		THEN( "the element does not contain children" ) {
			CHECK( element.child_count() == 0 );
		}
		THEN( "the element does not have a parent set" ) {
			CHECK( element.parent() == nullptr );
		}
		THEN( "bounds are at 0, 0 and size is 0 * 0" ) {
			CHECK(
				element.bounds() ==
				mog::Rectangle<float>( 0.0f, 0.0f, 0.0f, 0.0f )
			);
		}
		THEN( "background color is white" ) {
			CHECK(
				element.background_color() == mog::Color( 1.0f, 1.0f, 1.0f, 1.0f )
			);
		}
	}
}

SCENARIO( "Elements can be appended", "[mog::Element]" ) {
	GIVEN( "an empty parent element" ) {
		mog::Element parent( "parent" );

		WHEN( "multiple elements are appended" ) {
			auto child0 = std::unique_ptr<mog::Element>( new mog::Element( "0" ) );
			auto child1 = std::unique_ptr<mog::Element>( new mog::Element( "1" ) );
			auto child2 = std::unique_ptr<mog::Element>( new mog::Element( "2" ) );

			const auto* child0_ptr = child0.get();
			const auto* child1_ptr = child1.get();
			const auto* child2_ptr = child2.get();

			parent.append( std::move( child0 ) );
			parent.append( std::move( child1 ) );
			parent.append( std::move( child2 ) );

			THEN( "the child count equals the amount of appended elements" ) {
				REQUIRE( parent.child_count() == 3 );
			}
			THEN( "the order of children is the same in which they were appended" ) {
				CHECK( &parent.child( 0 ) == child0_ptr );
				CHECK( &parent.child( 1 ) == child1_ptr );
				CHECK( &parent.child( 2 ) == child2_ptr );
			}
			THEN( "the parent of each child is the actual parent" ) {
				CHECK( parent.child( 0 ).parent() == &parent );
				CHECK( parent.child( 1 ).parent() == &parent );
				CHECK( parent.child( 2 ).parent() == &parent );
			}
		}
	}
}

SCENARIO( "Element bounds can be changed.", "[mog::Element]" ) {
	GIVEN( "a default element and new bounds" ) {
		mog::Element element( "default" );
		mog::Rectangle<float> new_bounds( 1.0f, 2.0f, 3.0f, 4.0f );

		REQUIRE( element.bounds() != new_bounds );

		WHEN( "element's bounds are changed" ) {
			element.bounds( new_bounds );

			THEN( "they are equal to the new bounds" ) {
				CHECK( element.bounds() == new_bounds );
			}
		}
	}
}

SCENARIO( "Background color can be changed.", "[mog::Element" ) {
	GIVEN( "a default element and a new color" ) {
		mog::Element element( "default" );
		mog::Color new_color( 0.1f, 0.2f, 0.3f, 0.4f );

		REQUIRE( element.background_color() != new_color );

		WHEN( "element's background color is changed" ) {
			element.background_color( new_color );

			THEN( "it's equal to the new color" ) {
				CHECK( element.background_color() == new_color );
			}
		}
	}
}
