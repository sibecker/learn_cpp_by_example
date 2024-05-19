cmake_minimum_required(VERSION 3.12)

project(chapter2)

add_library(chapter2 STATIC
        triangle.cpp
)
target_link_libraries(chapter2 PUBLIC ch2-headers)

add_executable(ch2-main
        main.cpp
)
target_link_libraries(ch2-main PUBLIC chapter2)
