cmake_minimum_required(VERSION 3.20)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOLUTION_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/leetcode/*.cpp"
    "${CMAKE_SOURCE_DIR}/neetcode/*.cpp")

add_executable(leetcode main.cpp ${SOLUTION_SOURCES})
target_include_directories(leetcode PRIVATE "${CMAKE_SOURCE_DIR}/include")
