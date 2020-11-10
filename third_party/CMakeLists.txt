cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

add_subdirectory(box2d)
add_subdirectory(benchmark)
add_subdirectory(google_test)
add_subdirectory(glfw)
add_subdirectory(glog)
# add_subdirectory(fcl)


