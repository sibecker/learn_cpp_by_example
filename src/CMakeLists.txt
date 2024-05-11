cmake_minimum_required(VERSION 3.12)

project(learn-C++)

add_executable(learn
        main.cpp
)
target_link_libraries(learn PUBLIC learn-headers)
