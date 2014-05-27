#include <mogui/drawable_container.hpp>
#include <mogui/color.hpp>
#include <catch.hpp>

class DummyContainer : public mog::DrawableContainer {
	public:
		using mog::DrawableContainer::Change;

		DummyContainer() :
			mog::DrawableContainer(),
			_last_id( 1337 ),
			_last_change( 255 )
		{
		}

		Change get_last_change() const {
			return static_cast<Change>( _last_change );
		}

		std::size_t get_last_id() const {
			return _last_id;
		}

	private:
		void on_drawable_change( std::size_t index, Change what ) override {
			_last_id = index;
			_last_change = static_cast<uint8_t>( what );
		}

		std::size_t _last_id;
		uint8_t _last_change;
};

const mog::Color BLACK_COLOR( 0, 0, 0, 1 );
const mog::Color RED_COLOR( 1, 0, 0, 1 );
const mog::Color GREEN_COLOR( 0, 1, 0, 1 );
const mog::Color BLUE_COLOR( 0, 0, 1, 1 );

SCENARIO( "Construct DrawableContainers." ) {
	WHEN( "the default constructor is used" ) {
		mog::DrawableContainer container;

		THEN( "the drawable count is 0" ) {
			CHECK( container.get_drawable_count() == 0 );
		}
	}
}

SCENARIO( "Create drawable in DrawableContainer." ) {
	GIVEN( "an empty DrawableContainer" ) {
		mog::DrawableContainer container;

		WHEN( "2 drawables are created" ) {
			std::vector<std::size_t> ids;

			ids.push_back( container.create_drawable() );
			ids.push_back( container.create_drawable() );

			THEN( "the drawable count is 2" ) {
				CHECK( container.get_drawable_count() == 2 );
			}

			THEN( "the drawable IDs are sequential and start at 0" ) {
				CHECK( ids[0] == 0 );
				CHECK( ids[1] == 1 );
			}

			THEN( "the color of the drawables is black" ) {
				CHECK( container.get_drawable_color( 0 ) == BLACK_COLOR );
				CHECK( container.get_drawable_color( 1 ) == BLACK_COLOR );
			}
		}
	}
}

SCENARIO( "Reset DrawableContainer." ) {
	GIVEN( "a DrawableContainer with some drawables" ) {
		mog::DrawableContainer container;
		container.create_drawable();
		container.create_drawable();
		container.create_drawable();

		WHEN( "DrawableContainer is reset" ) {
			container.reset();

			THEN( "all drawables are removed" ) {
				CHECK( container.get_drawable_count() == 0 );
			}

			THEN( "the ID of the next newly created drawable starts at 0 again" ) {
				CHECK( container.create_drawable() == 0 );
			}
		}
	}
}

SCENARIO( "Change drawable color." ) {
	GIVEN( "a DrawableContainer with some drawables" ) {
		mog::DrawableContainer container;
		container.create_drawable();
		container.create_drawable();
		container.create_drawable();
		
		WHEN( "the colors are changed" ) {
			container.set_drawable_color( 0, RED_COLOR );
			container.set_drawable_color( 1, GREEN_COLOR );
			container.set_drawable_color( 2, BLUE_COLOR );

			THEN( "the drawable colors are set accordingly" ) {
				CHECK( container.get_drawable_color( 0 ) == RED_COLOR );
				CHECK( container.get_drawable_color( 1 ) == GREEN_COLOR );
				CHECK( container.get_drawable_color( 2 ) == BLUE_COLOR );
			}
		}
	}
}

SCENARIO( "Notify derived DrawableContainer of drawable changes." ) {
	GIVEN( "a container with a drawable" ) {
		DummyContainer container;
		container.create_drawable();

		WHEN( "the color of a drawable is changed" ) {
			container.set_drawable_color( 0, RED_COLOR );

			THEN( "the change type is COLOR" ) {
				CHECK( container.get_last_change() == DummyContainer::Change::COLOR );
			}
			THEN( "the drawable ID is 0" ) {
				CHECK( container.get_last_id() == 0 );
			}
		}
	}
}
