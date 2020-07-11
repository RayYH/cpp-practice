cmake_minimum_required(VERSION 2.8.2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(vendor)

file(GLOB_RECURSE CPP_PRACTICE_TESTS_SOURCES "src/*.cpp")

add_executable(
        tests
        ${CPP_PRACTICE_TESTS_SOURCES}
)
add_test(NAME check COMMAND tests)

target_include_directories(
        tests
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../src
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/misc
)

# Link against Google Test library
target_link_libraries(tests gmock_main)
