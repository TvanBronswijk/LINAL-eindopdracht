cmake_minimum_required(VERSION 3.8)

enable_testing()
add_executable(vector2d test_vector2D.cpp)
target_link_libraries(vector2d PRIVATE engine)
add_test(NAME vector2d COMMAND vector2d)

add_executable(vector3d test_vector3D.cpp)
target_link_libraries(vector3d PRIVATE engine)
add_test(NAME vector3d COMMAND vector3d)