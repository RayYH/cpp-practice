cmake_minimum_required(VERSION 2.8.2)
project(cpp_practice)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(
        cpp_practice
        src/main.cpp
        src/obj.cpp
        src/obj_operations.cpp
)

target_include_directories(
        cpp_practice
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/include
)

# Uncomment for tests
include(CTest)
enable_testing()

if (BUILD_TESTING)
    add_subdirectory(tests)
endif ()
