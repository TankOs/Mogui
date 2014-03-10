#include <mogui/event.hpp>
#include <cassert>
#include <cstring>

namespace mog {

Event::Event( Action action ) :
	_sender( nullptr ),
	_action( action )
{
	memset( &_mouse_move_data, 0, sizeof( _mouse_move_data ) );
	memset( &_mouse_button_data, 0, sizeof( _mouse_button_data ) );
	memset( &_key_data, 0, sizeof( _key_data ) );
}

Event::Action Event::action() const {
	return _action;
}

Element* Event::sender() const {
	return _sender;
}

Vector2<uint16_t> Event::mouse_position() const {
	assert(
		"Mouse position not valid for current event action." && (
			_action == Action::MOUSE_MOVE ||
			_action == Action::MOUSE_BUTTON_PRESS ||
			_action == Action::MOUSE_BUTTON_RELEASE
		)
	);

	return (
		_action == Action::MOUSE_MOVE ?
		_mouse_move_data.position :
		_mouse_button_data.position
	);
}

Event::MouseButton Event::mouse_button() const {
	assert(
		"Mouse button not valid for current event action." && (
			_action == Action::MOUSE_BUTTON_PRESS ||
			_action == Action::MOUSE_BUTTON_RELEASE
		)
	);

	return _mouse_button_data.button;
}

uint32_t Event::key() const {
	assert(
		"Key not valid for current event action." && (
			_action == Action::KEY_PRESS ||
			_action == Action::KEY_RELEASE
		)
	);

	return _key_data.key;
}

}
