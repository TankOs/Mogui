#include <mogui/vector2.hpp>
#include <catch.hpp>

SCENARIO( "Construct Vector2." ) {
  WHEN( "Default constructor is used" ) {
    mog::Vector2<float> vector;

    THEN( "x and y components are zero" ) {
      CHECK( vector.get_x() == 0.0f );
      CHECK( vector.get_y() == 0.0f );
    }
  }

  WHEN( "x/y constructor is used" ) {
    mog::Vector2<float> vector( 1.0f, 2.0f );

    THEN( "values are taken over" ) {
      CHECK( vector.get_x() == 1.0f );
      CHECK( vector.get_y() == 2.0f );
    }
  }
}

SCENARIO( "Vector2 algebra." ) {
  GIVEN( "two Vector2<float>s" ) {
    mog::Vector2<float> v0( 1.0f, 2.0f );
    mog::Vector2<float> v1( 3.0f, 4.0f );

    WHEN( "vectors are added" ) {
      auto result = v0 + v1;

      THEN( "the result is the sum of both" ) {
        CHECK( result.get_x() == v0.get_x() + v1.get_x() );
        CHECK( result.get_y() == v0.get_y() + v1.get_y() );
      }
    }

    WHEN( "vectors are subtracted" ) {
      auto result = v0 - v1;

      THEN( "the result is the difference of both" ) {
        CHECK( result.get_x() == v0.get_x() - v1.get_x() );
        CHECK( result.get_y() == v0.get_y() - v1.get_y() );
      }
    }

    WHEN( "a vector is incremented by another" ) {
      auto result = v0;
      auto& result_object = (result += v1);

      THEN( "the result is the first vector incremented by the second" ) {
        CHECK( result.get_x() == v0.get_x() + v1.get_x() );
        CHECK( result.get_y() == v0.get_y() + v1.get_y() );
      }

      THEN( "the resulting object is the same as the first vector" ) {
        CHECK( &result_object == &result );
      }
    }

    WHEN( "a vector is decremented by another" ) {
      auto result = v0;
      auto& result_object = (result -= v1);

      THEN( "the result is the first vector decremented by the second" ) {
        CHECK( result.get_x() == v0.get_x() - v1.get_x() );
        CHECK( result.get_y() == v0.get_y() - v1.get_y() );
      }

      THEN( "the resulting object is the same as the first vector" ) {
        CHECK( &result_object == &result );
      }
    }
  }
}

SCENARIO( "Predefined Vector2 typenames." ) {
  WHEN( "Vector2f is used" ) {
    THEN( "the type is equal to Vector2<float>" ) {
      CHECK( typeid( mog::Vector2f ) == typeid( mog::Vector2<float> ) );
    }
  }

  WHEN( "Vector2i32 is used" ) {
    THEN( "the type is equal to Vector2<int32_t>" ) {
      CHECK( typeid( mog::Vector2i32 ) == typeid( mog::Vector2<int32_t> ) );
    }
  }

  WHEN( "Vector2i16 is used" ) {
    THEN( "the type is equal to Vector2<int16_t>" ) {
      CHECK( typeid( mog::Vector2i16 ) == typeid( mog::Vector2<int16_t> ) );
    }
  }

  WHEN( "Vector2i8 is used" ) {
    THEN( "the type is equal to Vector2<int8_t>" ) {
      CHECK( typeid( mog::Vector2i8 ) == typeid( mog::Vector2<int8_t> ) );
    }
  }

  WHEN( "Vector2u32 is used" ) {
    THEN( "the type is equal to Vector2<int32_t>" ) {
      CHECK( typeid( mog::Vector2u32 ) == typeid( mog::Vector2<uint32_t> ) );
    }
  }

  WHEN( "Vector2u16 is used" ) {
    THEN( "the type is equal to Vector2<int16_t>" ) {
      CHECK( typeid( mog::Vector2u16 ) == typeid( mog::Vector2<uint16_t> ) );
    }
  }

  WHEN( "Vector2u8 is used" ) {
    THEN( "the type is equal to Vector2<int8_t>" ) {
      CHECK( typeid( mog::Vector2u8 ) == typeid( mog::Vector2<uint8_t> ) );
    }
  }
}

SCENARIO( "Compare Vector2 equality." ) {
  GIVEN( "two unequal vectors" ) {
    mog::Vector2<float> vector0( 1.0f, 2.0f );
    mog::Vector2<float> vector1( 4.0f, 3.0f );

    WHEN( "the vectors are compared" ) {
      CHECK( (vector0 == vector1) == false );
      CHECK( (vector0 != vector1) == true );
    }
  }

  GIVEN( "two equal vectors" ) {
    mog::Vector2<float> vector0( 1.0f, 2.0f );
    mog::Vector2<float> vector1( 1.0f, 2.0f );

    WHEN( "the vectors are compared" ) {
      CHECK( (vector0 == vector1) == true );
      CHECK( (vector0 != vector1) == false );
    }
  }
}
