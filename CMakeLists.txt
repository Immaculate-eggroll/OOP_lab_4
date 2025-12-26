cmake_minimum_required(VERSION 3.14)
project(lab4)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)

add_executable(lab4_main main.cpp)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
set(gtest_force_shared_crt OFF)
set(BUILD_SHARED_LIBS OFF)
FetchContent_MakeAvailable(googletest)

add_executable(lab4_tests tests.cpp)
target_link_libraries(lab4_tests PRIVATE gtest gtest_main)
