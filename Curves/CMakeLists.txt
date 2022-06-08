cmake_minimum_required(VERSION 3.14)

project(Curves LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

set(SOURCE_FILES
    curves.cpp
)

set(HEADER_FILES
   curves.h
)

add_library(Curves SHARED ${SOURCE_FILES} ${HEADER_FILES})
