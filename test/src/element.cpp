#include <mogui/element.hpp>
#include <mogui/event.hpp>
#include <catch.hpp>

class TestElement : public mog::Element {
	public:
		TestElement() :
			mog::Element( "test" ),
			_received_event_count( 0 ),
			_last_event( mog::Event::Action::MOUSE_MOVE )
		{
		}

		mog::Event last_event() const {
			return _last_event;
		}

		uint32_t received_event_count() const {
			return _received_event_count;
		}

	private:
		void on_event( mog::Event& event ) {
			++_received_event_count;
			_last_event = event;
		}

		uint32_t _received_event_count;
		mog::Event _last_event;
};

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
		THEN( "area is at 0, 0 and size is 0 * 0" ) {
			CHECK(
				element.area() ==
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

SCENARIO( "Element area can be changed.", "[mog::Element]" ) {
	GIVEN( "a default element" ) {
		mog::Element element( "default" );
		mog::Rectangle<float> new_area( 1.0f, 2.0f, 3.0f, 4.0f );

		REQUIRE( element.area() != new_area );

		WHEN( "element's area is changed" ) {
			element.area( new_area );

			THEN( "they are equal to the new area" ) {
				CHECK( element.area() == new_area );
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

SCENARIO( "Events can be inserted into an element hierarchy" ) {
	GIVEN( "an element hiararchy and a key press event" ) {
		using mog::Element;
		using mog::Event;

		Event event( Event::Action::KEY_PRESS );

		TestElement root;
		root.append( std::unique_ptr<TestElement>( new TestElement ) );
		auto& level0 = *static_cast<TestElement*>( &root.child( 0 ) );

		level0.append( std::unique_ptr<TestElement>( new TestElement ) );
		auto& level1 = *static_cast<TestElement*>( &level0.child( 0 ) );

		WHEN( "an event is inserted at the root node" ) {
			root.propagate( event );

			THEN( "the root element processed the event" ) {
				CHECK( root.last_event().action() == Event::Action::KEY_PRESS );
				CHECK( root.received_event_count() == 1 );
			}

			THEN( "the level0 element processed the event" ) {
				CHECK( level0.last_event().action() == Event::Action::KEY_PRESS );
				CHECK( level0.received_event_count() == 1 );
			}

			THEN( "the level1 element processed the event" ) {
				CHECK( level1.last_event().action() == Event::Action::KEY_PRESS );
				CHECK( level1.received_event_count() == 1 );
			}
		}
	}
}
