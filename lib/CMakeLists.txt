cmake_minimum_required( VERSION 2.8 )
project( mogui-lib )

set( SRC_PATH ${PROJECT_SOURCE_DIR}/src )
set( INC_PATH ${PROJECT_SOURCE_DIR}/include )

set(
	SOURCES
	${INC_PATH}/mogui/color.hpp
	${INC_PATH}/mogui/config.hpp
	${INC_PATH}/mogui/element.hpp
	${INC_PATH}/mogui/opengl_es_renderer.hpp
	${INC_PATH}/mogui/renderer.hpp
	${SRC_PATH}/mogui/color.cpp
	${SRC_PATH}/mogui/config.cpp
	${SRC_PATH}/mogui/element.cpp
	${SRC_PATH}/mogui/opengl_es_renderer.cpp
)

include_directories( ${INC_PATH} )

add_library( mogui SHARED ${SOURCES} )
