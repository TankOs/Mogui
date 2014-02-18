#include <mogui/rectangle.hpp>
#include <catch.hpp>

SCENARIO( "Rectangle can be constructed", "[mog::Rectangle]" ) {
	WHEN( "default constructor is used" ) {
		mog::Rectangle<float> rectangle;

		CHECK( rectangle.left() == 0.0f );
		CHECK( rectangle.top() == 0.0f );
		CHECK( rectangle.width() == 0.0f );
		CHECK( rectangle.height() == 0.0f );
	}

	WHEN( "left/top/width/height constructor is used" ) {
		mog::Rectangle<float> rectangle( 1.0f, 2.0f, 3.0f, 4.0f );

		CHECK( rectangle.left() == 1.0f );
		CHECK( rectangle.top() == 2.0f );
		CHECK( rectangle.width() == 3.0f );
		CHECK( rectangle.height() == 4.0f );
	}
}

SCENARIO( "Basic properties can be changed.", "[mog::Rectangle]" ) {
	GIVEN( "default-constructed float Rectangle" ) {
		mog::Rectangle<float> rectangle;

		WHEN( "left, top, width, height are changed individually" ) {
			rectangle.left( 1.0f );
			rectangle.top( 2.0f );
			rectangle.width( 3.0f );
			rectangle.height( 4.0f );
			
			THEN( "properties are set accordingly" ) {
				CHECK( rectangle.left() == 1.0f );
				CHECK( rectangle.top() == 2.0f );
				CHECK( rectangle.width() == 3.0f );
				CHECK( rectangle.height() == 4.0f );
			}
		}

	}
}

SCENARIO(
	"location and size can be used instead of left, top, width, height",
	"[mog::Rectangle]"
) {
	GIVEN( "default-constructed float Rectangle" ) {
		mog::Rectangle<float> rectangle;

		WHEN( "location and size are changed" ) {
			rectangle.location( {1.0f, 2.0f} );
			rectangle.size( {3.0f, 4.0f} );
			
			THEN( "properties are set accordingly" ) {
				CHECK( rectangle.location() == mog::Vector2<float>( 1.0f, 2.0f ) );
				CHECK( rectangle.size() == mog::Vector2<float>( 3.0f, 4.0f ) );

				CHECK( rectangle.left() == 1.0f );
				CHECK( rectangle.top() == 2.0f );
				CHECK( rectangle.width() == 3.0f );
				CHECK( rectangle.height() == 4.0f );
			}
		}

	}

}

SCENARIO( "Rectangles can be compared for equality.", "[mog::Rectangle]" ) {
	GIVEN( "two unequal rectangles" ) {
		mog::Rectangle<float> rectangle0( 1.0f, 2.0f, 3.0f, 4.0f );
		mog::Rectangle<float> rectangle1( 4.0f, 3.0f, 2.0f, 1.0f );

		WHEN( "the rectangles are compared" ) {
			CHECK( (rectangle0 == rectangle1) == false );
			CHECK( (rectangle0 != rectangle1) == true );
		}
	}

	GIVEN( "two equal rectangles" ) {
		mog::Rectangle<float> rectangle0( 1.0f, 2.0f, 3.0f, 4.0f );
		mog::Rectangle<float> rectangle1( 1.0f, 2.0f, 3.0f, 4.0f );

		WHEN( "the rectangles are compared" ) {
			CHECK( (rectangle0 == rectangle1) == true );
			CHECK( (rectangle0 != rectangle1) == false );
		}
	}
}
