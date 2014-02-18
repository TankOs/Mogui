#include <mogui/color.hpp>
#include <catch.hpp>

SCENARIO( "Color can be constructed", "[mog::Color]" ) {
	WHEN( "default constructor is used" ) {
		THEN( "all colors and alpha are 0" ) {
			mog::Color color;

			CHECK( color.r() == 0.0f );
			CHECK( color.g() == 0.0f );
			CHECK( color.b() == 0.0f );
			CHECK( color.a() == 1.0f );
		}
	}

	WHEN( "r, g, b constructor is used" ) {
		THEN( "r, g, b are set as specified and a is 1" ) {
			mog::Color color( 0.1f, 0.2f, 0.3f );

			CHECK( color.r() == 0.1f );
			CHECK( color.g() == 0.2f );
			CHECK( color.b() == 0.3f );
			CHECK( color.a() == 1.0f );
		}
	}

	WHEN( "r, g, b, a constructor is used" ) {
		THEN( "r, g, b, a are set accordingly" ) {
			mog::Color color( 0.1f, 0.2f, 0.3f, 0.4f );

			CHECK( color.r() == 0.1f );
			CHECK( color.g() == 0.2f );
			CHECK( color.b() == 0.3f );
			CHECK( color.a() == 0.4f );
		}
	}
}

SCENARIO( "Basic properties can be changed", "[mog::Color]" ) {
	GIVEN( "a default-constructed color" ) {
		mog::Color color;

		WHEN( "components are changed individually" ) {
			color.r( 0.1f );
			color.g( 0.2f );
			color.b( 0.3f );
			color.a( 0.4f );

			THEN( "components are set accordingly" ) {
				CHECK( color.r() == 0.1f );
				CHECK( color.g() == 0.2f );
				CHECK( color.b() == 0.3f );
				CHECK( color.a() == 0.4f );
			}
		}

		WHEN( "r, g, b are set together" ) {
			color.rgb( 0.1f, 0.2f, 0.3f );

			THEN( "components are set accordingly" ) {
				CHECK( color.r() == 0.1f );
				CHECK( color.g() == 0.2f );
				CHECK( color.b() == 0.3f );
			}

			THEN( "alpha is unchanged" ) {
				CHECK( color.a() == 1.0f );
			}
		}

		WHEN( "all components are set together" ) {
			color.rgba( 0.1f, 0.2f, 0.3f, 0.4f );

			THEN( "components are set accordingly" ) {
				CHECK( color.r() == 0.1f );
				CHECK( color.g() == 0.2f );
				CHECK( color.b() == 0.3f );
				CHECK( color.a() == 0.4f );
			}
		}
	}
}

SCENARIO( "Colors can be compared.", "[mog::Color]" ) {
	GIVEN( "colors with different elements" ) {
		mog::Color color_z( 0.0f, 0.0f, 0.0f, 0.0f );
		mog::Color color_r( 1.0f, 0.0f, 0.0f, 0.0f );
		mog::Color color_g( 0.0f, 1.0f, 0.0f, 0.0f );
		mog::Color color_b( 0.0f, 0.0f, 1.0f, 0.0f );
		mog::Color color_a( 0.0f, 0.0f, 0.0f, 1.0f );

		WHEN( "black/transparent and red are compared" ) {
			THEN( "equality is false" ) {
				CHECK( (color_z == color_r) == false );
			}
			THEN( "inequality is true" ) {
				CHECK( (color_z != color_r) == true );
			}
		}

		WHEN( "black/transparent and green are compared" ) {
			THEN( "equality is false" ) {
				CHECK( (color_z == color_g) == false );
			}
			THEN( "inequality is true" ) {
				CHECK( (color_z != color_g) == true );
			}
		}

		WHEN( "black/transparent and blue are compared" ) {
			THEN( "equality is false" ) {
				CHECK( (color_z == color_b) == false );
			}
			THEN( "inequality is true" ) {
				CHECK( (color_z != color_b) == true );
			}
		}

		WHEN( "black/transparent and black are compared" ) {
			THEN( "equality is false" ) {
				CHECK( (color_z == color_a) == false );
			}
			THEN( "inequality is true" ) {
				CHECK( (color_z != color_a) == true );
			}
		}
	}
}
