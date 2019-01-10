cmake_minimum_required(VERSION 3.8)

enable_testing()
add_library(test_main OBJECT test_setup.cpp)
add_executable(test1 test1.cpp $<TARGET_OBJECTS:test_main>)
target_link_libraries(test1 PRIVATE engine)
add_test(NAME lol COMMAND test1)