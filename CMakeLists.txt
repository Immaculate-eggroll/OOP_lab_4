cmake_minimum_required(VERSION 3.16)
project(OOP_Lab4)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(main main.cpp)

find_package(GTest REQUIRED)
add_executable(tests tests.cpp)
target_link_libraries(tests GTest::gtest GTest::gtest_main)
