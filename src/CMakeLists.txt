cmake_minimum_required(VERSION 3.12)

project(learn-C++)

add_library(learn STATIC
        learn.cpp
        learn.cpp
)
target_link_libraries(learn PUBLIC learn-headers)

add_executable(main
        main.cpp
)
target_link_libraries(main PUBLIC learn)
