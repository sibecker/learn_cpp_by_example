cmake_minimum_required(VERSION 3.12)

add_executable(ch2-tests tests.cpp)
target_link_libraries(ch2-tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(ch2-tests PUBLIC chapter2)

catch_discover_tests(ch2-tests)
