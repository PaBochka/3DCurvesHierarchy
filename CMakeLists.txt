cmake_minimum_required(VERSION 3.14)

project(3DCurvesHierarchy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

find_package(OpenMP REQUIRED)

add_subdirectory(Curves)

add_executable(3DCurvesHierarchy
  main.cpp
)
target_link_libraries(3DCurvesHierarchy PUBLIC Curves OpenMP::OpenMP_CXX)
