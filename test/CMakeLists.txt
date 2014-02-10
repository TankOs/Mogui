cmake_minimum_required( VERSION 2.8 )
project( mogui-test )

set( SRC_DIR ${PROJECT_SOURCE_DIR}/src )

set(
	SOURCES
	${SRC_DIR}/config.cpp
)

include_directories( ${PROJECT_SOURCE_DIR}/../ext_libs/catch/include )

add_executable( mogui-test ${SOURCES} )

target_link_libraries(
	mogui-test
	mogui
)
