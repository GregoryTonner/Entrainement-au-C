cmake_minimum_required(VERSION 3.24)
project(main C)

set(CMAKE_C_STANDARD 11)

add_executable(main main.c test.c test.h)