cmake_minimum_required(VERSION 3.23)
project(c_things C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(c_things
        test.c
        utils.h)
