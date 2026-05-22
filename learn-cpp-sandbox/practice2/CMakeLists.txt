cmake_minimum_required(VERSION 3.15)
project(MyProject VERSION 1.0 LANGUAGES CXX)

# 1. Enforce C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Fix the MSVC macro reporting quirk
if(MSVC)
    add_compile_options(/Zc:__cplusplus)
endif()

add_executable(practice2 main.cpp)