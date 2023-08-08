cmake_minimum_required(VERSION 3.25)
project(TodoList)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)

set(SOURCE_FILES Event.cpp Event.h EventList.cpp EventList.h)
add_executable(TodoList main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(TodoList core)