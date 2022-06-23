cmake_minimum_required(VERSION 3.14)

project(ClassIdent LANGUAGES CXX VERSION 1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)
