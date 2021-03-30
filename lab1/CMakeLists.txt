cmake_minimum_required(VERSION 3.16 )

# set the project name
project(lab1 C)

set(CMAKE_C_STANDART 11)

#include directories(.)

# add the executable
add_executable(
        main main.c

        ${CMAKE_SOURCE_DIR}/library/array.c
        ${CMAKE_SOURCE_DIR}/library/array.h

        ${CMAKE_SOURCE_DIR}/library/lib_int_algebra.h
        ${CMAKE_SOURCE_DIR}/library/lib_int_algebra.c

        ${CMAKE_SOURCE_DIR}/library/lib_float_algebra.h
        ${CMAKE_SOURCE_DIR}/library/lib_float_algebra.c

        )
