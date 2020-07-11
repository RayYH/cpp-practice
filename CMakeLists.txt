cmake_minimum_required(VERSION 2.8.2)

if (POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW)
endif (POLICY CMP0048)

project(cpp_practice)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE CPP_PRACTICE_SOURCES "src/*.cpp")
file(GLOB_RECURSE CPP_PRACTICE_HEADERS "src/*.hpp")

set(CPP_PRACTICE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src/include)
foreach (_headerFile ${CPP_PRACTICE_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list(APPEND CPP_PRACTICE_INCLUDE_DIRS ${_dir})
endforeach ()
list(REMOVE_DUPLICATES CPP_PRACTICE_INCLUDE_DIRS)

add_executable(cpp_practice ${CPP_PRACTICE_SOURCES})
target_include_directories(cpp_practice PUBLIC ${CPP_PRACTICE_INCLUDE_DIRS})

# Uncomment for tests
include(CTest)
enable_testing()

if (BUILD_TESTING)
    add_subdirectory(tests)
endif ()
