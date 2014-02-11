cmake_minimum_required( VERSION 2.8 )
project( mogui-lib )

set( SRC_PATH ${PROJECT_SOURCE_DIR}/src )
set( INC_PATH ${PROJECT_SOURCE_DIR}/include )

set(
	SOURCES
	${INC_PATH}/mogui/config.hpp
	${INC_PATH}/mogui/element.hpp
	${SRC_PATH}/mogui/config.cpp
	${SRC_PATH}/mogui/element.cpp
)

include_directories( ${INC_PATH} )

add_library( mogui SHARED ${SOURCES} )
