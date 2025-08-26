cmake_minimum_required(VERSION 3.5)

project(containers_tests)
enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(containers_tests 
    myvector_tests.cpp
    mylist_tests.cpp
)

target_link_libraries(containers_tests gtest_main)
target_include_directories(containers_tests PUBLIC ../include)

include(GoogleTest)
gtest_discover_tests(containers_tests)
