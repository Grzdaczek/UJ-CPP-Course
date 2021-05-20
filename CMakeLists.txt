cmake_minimum_required(VERSION 3.10)

project(ujcpp VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

file(GLOB SOURCES "src/*.cpp")

add_executable(ujcpp ${SOURCES})

target_include_directories(ujcpp
	PRIVATE 
		${PROJECT_SOURCE_DIR}/include
)