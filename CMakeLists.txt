cmake_minimum_required(VERSION 3.19)
project(simple_binary_search)

set(CMAKE_CXX_STANDARD 20)
Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)


add_executable(simple_binary_search src/main.cpp binary_search.hpp src/test/string.cpp)
target_link_libraries(simple_binary_search Catch2::Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(CTest)
include(Catch)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(CTest)
include(Catch)

catch_discover_tests(simple_binary_search)

