cmake_minimum_required(VERSION 3.5.1)

# https://cmake.org/cmake/help/latest/command/project.html
project(box2d VERSION 2.4.0)

file(GLOB HEADER_FILES
        Box2D/include/*)
		
file(GLOB SOURCE_FILES
        Box2D/src/collision/*
        Box2D/src/common/*)

add_library(box2d
        ${HEADER_FILES}
        ${SOURCE_FILES})
target_include_directories(box2d 
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Box2D/src/
        ${CMAKE_CURRENT_SOURCE_DIR}/Box2D/include/
)

