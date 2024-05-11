cmake_minimum_required(VERSION 3.12)

project(learn-headers)

add_library(learn-headers INTERFACE
        learn.h)
target_include_directories(learn-headers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

