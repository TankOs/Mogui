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
}
