#include <mogui/opengl_es_renderer.hpp>
#include <catch.hpp>

const mog::Color RED( 1.0f, 0.0f, 0.0f );
const mog::Color GREEN( 0.0f, 0.0f, 1.0f );
const mog::Color BLUE( 0.0f, 0.0f, 1.0f );
const mog::Color BLACK( 0.0f, 0.0f, 0.0f );

SCENARIO( "Can be constructed.", "[mog::OpenGLESRenderer]" ) {
	WHEN( "default constructor is used" ) {
		mog::OpenGLESRenderer renderer;

		THEN( "no drawables are present" ) {
			CHECK( renderer.drawable_count() == 0 );
		}
	}
}

SCENARIO( "Drawable count can be set.", "[mog::OpenGLESRenderer]" ) {
	GIVEN( "an empty renderer" ) {
		mog::OpenGLESRenderer renderer;

		REQUIRE( renderer.drawable_count() == 0 );

		WHEN( "drawable count is set to 2" ) {
			renderer.drawable_count( 2 );

			THEN( "the renderer has 2 drawables" ) {
				CHECK( renderer.drawable_count() == 2 );
			}

			THEN( "the drawables are black" ) {
				CHECK( renderer.drawable_color( 0 ) == BLACK );
				CHECK( renderer.drawable_color( 1 ) == BLACK );
			}
		}
	}

	GIVEN( "a renderer with some color-coded drawables" ) {
		mog::OpenGLESRenderer renderer;

		renderer.drawable_count( 3 );
		renderer.drawable_color( 0, RED );
		renderer.drawable_color( 1, GREEN );
		renderer.drawable_color( 2, BLUE );

		REQUIRE( renderer.drawable_color( 0 ) == RED );
		REQUIRE( renderer.drawable_color( 1 ) == GREEN );
		REQUIRE( renderer.drawable_color( 2 ) == BLUE );

		WHEN( "drawable count is increased" ) {
			renderer.drawable_count( 4 );

			THEN( "the old drawables are preserved" ) {
				CHECK( renderer.drawable_color( 0 ) == RED );
				CHECK( renderer.drawable_color( 1 ) == GREEN );
				CHECK( renderer.drawable_color( 2 ) == BLUE );
			}
		}

		WHEN( "drawable count is decreased" ) {
			renderer.drawable_count( 2 );

			THEN( "the remaining drawables are preserved" ) {
				CHECK( renderer.drawable_color( 0 ) == RED );
				CHECK( renderer.drawable_color( 1 ) == GREEN );
			}
		}
	}
}

SCENARIO( "Drawable color can be changed.", "[mog::OpenGLESRenderer]" ) {
	GIVEN( "a renderer with two drawables" ) {
		mog::OpenGLESRenderer renderer;

		renderer.drawable_count( 2 );

		WHEN( "the colors are changed to red and blue" ) {

			renderer.drawable_color( 0, RED );
			renderer.drawable_color( 1, BLUE );

			THEN( "the first drawable's color is red" ) {
				CHECK( renderer.drawable_color( 0 ) == RED );
			}

			THEN( "the second drawable's color is blue" ) {
				CHECK( renderer.drawable_color( 1 ) == BLUE );
			}
		}
	}
}
