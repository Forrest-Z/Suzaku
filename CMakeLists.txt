cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")


find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)

add_subdirectory(third_party)

add_library(robot 
  src/shape.cc
  src/display.cc
  src/transform.cc)
# target_include_directories(robot )
target_link_libraries(robot 
${OpenCV_LIBS})


add_executable(example_test
  test/example_test.cc)
# target_include_directories()
target_link_libraries(example_test
  ${OpenCV_LIBS}
  robot)

add_executable(opengl_test
  test/opengl_test.cc)
# target_include_directories()
target_link_libraries(opengl_test
  ${OpenCV_LIBS}
  robot
  GL 
  glut)

