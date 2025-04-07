cmake_minimum_required(VERSION 3.25)

project(cpp_constructor_example LANGUAGES CXX)

# Check if sccache is installed, if not, skip configuration
find_program(SCCACHE sccache REQUIRED)

if(SCCACHE STREQUAL "SCCACHE-NOTFOUND")
    message(STATUS "sccache not found, skipping sccache configuration.")
else()
    message(STATUS "sccache found, configuring sccache.")
    set(CMAKE_C_COMPILER_LAUNCHER ${SCCACHE})
    set(CMAKE_CXX_COMPILER_LAUNCHER ${SCCACHE})
endif()

# C++ standard configuration
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cpp_constructor_example main.cpp)
