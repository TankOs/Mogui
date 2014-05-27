#include <mogui/rectangle.hpp>
#include <catch.hpp>

SCENARIO( "Construct Rectangle." ) {
	WHEN( "default constructor is used" ) {
		mog::Rectangle<float> rectangle;

		CHECK( rectangle.get_left() == 0.0f );
		CHECK( rectangle.get_top() == 0.0f );
		CHECK( rectangle.get_width() == 0.0f );
		CHECK( rectangle.get_height() == 0.0f );
	}

	WHEN( "left/top/width/height constructor is used" ) {
		mog::Rectangle<float> rectangle( 1.0f, 2.0f, 3.0f, 4.0f );

		CHECK( rectangle.get_left() == 1.0f );
		CHECK( rectangle.get_top() == 2.0f );
		CHECK( rectangle.get_width() == 3.0f );
		CHECK( rectangle.get_height() == 4.0f );
	}
}

SCENARIO( "Change Rectangle properties." ) {
	GIVEN( "default-constructed float Rectangle" ) {
		mog::Rectangle<float> rectangle;

		WHEN( "left, top, width, height are changed individually" ) {
			rectangle.set_left( 1.0f );
			rectangle.set_top( 2.0f );
			rectangle.set_width( 3.0f );
			rectangle.set_height( 4.0f );
			
			THEN( "properties are set accordingly" ) {
				CHECK( rectangle.get_left() == 1.0f );
				CHECK( rectangle.get_top() == 2.0f );
				CHECK( rectangle.get_width() == 3.0f );
				CHECK( rectangle.get_height() == 4.0f );
			}
		}

	}
}

SCENARIO( "Use Rectangle location and size instead of single properties." ) {
	GIVEN( "default-constructed float Rectangle" ) {
		mog::Rectangle<float> rectangle;

		WHEN( "location and size are changed" ) {
			rectangle.set_location( {1.0f, 2.0f} );
			rectangle.set_size( {3.0f, 4.0f} );
			
			THEN( "properties are set accordingly" ) {
				CHECK( rectangle.get_location() == mog::Vector2<float>( 1.0f, 2.0f ) );
				CHECK( rectangle.get_size() == mog::Vector2<float>( 3.0f, 4.0f ) );

				CHECK( rectangle.get_left() == 1.0f );
				CHECK( rectangle.get_top() == 2.0f );
				CHECK( rectangle.get_width() == 3.0f );
				CHECK( rectangle.get_height() == 4.0f );
			}
		}

	}

}

SCENARIO( "Compare Rectangle for equality." ) {
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
