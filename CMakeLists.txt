cmake_minimum_required(VERSION 3.20)
project(AMD_FSR)

set(CMAKE_CXX_STANDARD 11)

add_executable(AMD_FSR main.cpp Core/FSR.cpp Core/FSR.h Core/Point.cpp Core/Point.h Core/CommonProperty.cpp Core/CommonProperty.h)
