#pragma once

#include <mogui/vector2.hpp>
#include <cstdint>

namespace mog {

class Element;

class Event {
	public:
		enum class Action : uint8_t {
			MOUSE_MOVE = 0,
			MOUSE_BUTTON_PRESS,
			MOUSE_BUTTON_RELEASE,
			KEY_PRESS,
			KEY_RELEASE
		};

		enum class MouseButton : uint8_t {
			LEFT = 0,
			RIGHT,
			MIDDLE,
			FORWARD,
			BACKWARD
		};

		Event( Action action );

		Action get_action() const;

		Vector2<uint16_t> get_mouse_position() const;
		MouseButton get_mouse_button() const;

		uint32_t get_key() const;

	private:
		Action _action;

		struct MouseMoveData {
			Vector2<uint16_t> position;
		};

		struct MouseButtonData {
			Vector2<uint16_t> position;
			MouseButton button;
		};

		struct KeyData {
			uint32_t key;
		};

		union {
			MouseMoveData _mouse_move_data;
			MouseButtonData _mouse_button_data;
			KeyData _key_data;
		};
};

}

/** @class mog::Event
 * Event structure.
 */
