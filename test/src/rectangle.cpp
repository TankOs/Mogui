#include <mogui/rectangle.hpp>
#include <catch.hpp>

SCENARIO( "Rectangle can be constructed", "[mog::Rectangle]" ) {
	WHEN( "default constructor is used" ) {
		mog::Rectangle<float> rectangle;

		CHECK( rectangle.x == 0.0f );
		CHECK( rectangle.y == 0.0f );
		CHECK( rectangle.width == 0.0f );
		CHECK( rectangle.height == 0.0f );
	}

	WHEN( "x/y/width/height constructor is used" ) {
		mog::Rectangle<float> rectangle( 1.0f, 2.0f, 3.0f, 4.0f );

		CHECK( rectangle.x == 1.0f );
		CHECK( rectangle.y == 2.0f );
		CHECK( rectangle.width == 3.0f );
		CHECK( rectangle.height == 4.0f );
	}

	WHEN( "initializer list is used" ) {
		mog::Rectangle<float> rectangle = {1.0f, 2.0f, 3.0f, 4.0f};

		CHECK( rectangle.x == 1.0f );
		CHECK( rectangle.y == 2.0f );
		CHECK( rectangle.width == 3.0f );
		CHECK( rectangle.height == 4.0f );
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
