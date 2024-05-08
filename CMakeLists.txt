cmake_minimum_required(VERSION 3.28)
project(ArrayList C CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest)

include_directories(googletest googletest/googletest/include googletest/googletest/include/gtest)
add_executable(unittests googletest/googletest/src/gtest-all.cc
        test/test_ArrayList.cpp
        test/test_ArrayList.cpp)
add_library(ArrayList ArrayList.h
        ArrayList.c)
target_link_libraries(unittests ArrayList gtest gtest_main)
target_link_libraries(ArrayListDriver ArrayList)
