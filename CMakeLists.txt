cmake_minimum_required(VERSION 3.25)
project(TodoList)

set(CMAKE_CXX_STANDARD 17)

add_executable(TodoList main.cpp Event.cpp Event.h EventList.cpp EventList.h)
