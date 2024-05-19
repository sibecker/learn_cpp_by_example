cmake_minimum_required(VERSION 3.12)

project(ch2-headers)

add_library(ch2-headers INTERFACE
        triangle.h)
target_include_directories(ch2-headers INTERFACE .)

