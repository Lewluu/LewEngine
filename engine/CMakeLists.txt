cmake_minimum_required(VERSION 3.19.8)

set(CMAKE_MAKE_PROGRAM $ENV{MAKE} CACHE INTERNAL "")

project(LewEngine VERSION 1.0)

if(${MODE} STREQUAL test)

    set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
    set(LIB_DIR ${TEST_DIR}/src/lib)

    include(${TEST_DIR}/CMakeLists.txt)

endif()
