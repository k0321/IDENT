cmake_minimum_required(VERSION 3.14)

project(ident LANGUAGES CXX VERSION 1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(INCLUDE_FILES
    ${MY_INCLUDE_DIR}/main.h
    ${MY_INCLUDE_DIR}/identificator.h
)
set(SRC_FILES
    ./main.cpp
    ./identificator.cpp
)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${MY_INCLUDE_DIR})

find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
