cmake_minimum_required( VERSION 2.8 )
project( mogui-lib )

set( SRC_DIR ${PROJECT_SOURCE_DIR}/src )
set( INC_DIR ${PROJECT_SOURCE_DIR}/include )

set(
	SOURCES
	${INC_DIR}/mogui/config.hpp
	${SRC_DIR}/mogui/config.cpp
)

include_directories( ${INC_DIR} )

add_library( mogui SHARED ${SOURCES} )
