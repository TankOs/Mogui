cmake_minimum_required( VERSION 2.8 )
project( mogui-lib )

set( SRC_PATH ${PROJECT_SOURCE_DIR}/src )
set( INC_PATH ${PROJECT_SOURCE_DIR}/include )

set(
	SOURCES
	${INC_PATH}/mogui/action_handler.hpp
	${INC_PATH}/mogui/color.hpp
	${INC_PATH}/mogui/config.hpp
	${INC_PATH}/mogui/drawable_container.hpp
	${INC_PATH}/mogui/element.hpp
	${INC_PATH}/mogui/element_selector.hpp
	${INC_PATH}/mogui/event.hpp
	${INC_PATH}/mogui/event_propagator.hpp
	${INC_PATH}/mogui/opengl_es_renderer.hpp
	${INC_PATH}/mogui/renderer.hpp
	${SRC_PATH}/mogui/action_handler.cpp
	${SRC_PATH}/mogui/color.cpp
	${SRC_PATH}/mogui/config.cpp
	${SRC_PATH}/mogui/drawable_container.cpp
	${SRC_PATH}/mogui/element.cpp
	${SRC_PATH}/mogui/element_selector.cpp
	${SRC_PATH}/mogui/event.cpp
	${SRC_PATH}/mogui/event_propagator.cpp
	${SRC_PATH}/mogui/opengl_es_renderer.cpp
)

include_directories( ${INC_PATH} )

add_library( mogui SHARED ${SOURCES} )
