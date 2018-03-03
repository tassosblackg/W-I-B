cmake_minimum_required(VERSION 2.8)

project( CreateFiles )
set( CMAKE_EXECUTABLE_OUTPUT_PATH "build/${CreateFiles}" )
add_executable( createfiles createfiles.cpp )
