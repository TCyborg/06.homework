cmake_minimum_required(VERSION 3.5)

project(06.homework)

add_executable(main src/main.cpp)

include_directories(include)

set_target_properties(main PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_subdirectory(tests)