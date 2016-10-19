cmake_minimum_required(VERSION 3.6)
project(Probleme_Revision)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c main.h)
add_executable(Probleme_Revision ${SOURCE_FILES})
