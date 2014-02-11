cmake_minimum_required( VERSION 2.8 )
project( mogui-test )

set( SRC_PATH ${PROJECT_SOURCE_DIR}/src )

set(
	SOURCES
	${SRC_PATH}/config.cpp
	${SRC_PATH}/rectangle.cpp
	${SRC_PATH}/vector2.cpp
	${SRC_PATH}/element.cpp
)

include_directories( ${PROJECT_SOURCE_DIR}/../lib/include )
include_directories( ${PROJECT_SOURCE_DIR}/../ext_libs/catch/include )

add_executable( mogui-test ${SOURCES} )

target_link_libraries(
	mogui-test
	mogui
)

add_custom_command(
	TARGET mogui-test
	POST_BUILD
	WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
	COMMAND mogui-test
	COMMENT "Running unit tests..."
)
