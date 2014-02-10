cmake_minimum_required( VERSION 2.8 )
project( mogui )

enable_testing()

set( CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Wshadow -Wconversion -pedantic ${CMAKE_CXX_FLAGS}" )

add_subdirectory( lib )
add_subdirectory( test )
