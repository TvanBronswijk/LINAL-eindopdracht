cmake_minimum_required(VERSION 3.8)

enable_testing()
add_executable(vector2d test_vector2D.cpp)
target_link_libraries(vector2d PRIVATE engine)
add_test(NAME vector2D COMMAND vector2d)

add_executable(vector3d test_vector3D.cpp)
target_link_libraries(vector3d PRIVATE engine)
add_test(NAME vector3D COMMAND vector3d)

add_executable(matrix2d test_matrix2D.cpp)
target_link_libraries(matrix2d PRIVATE engine)
add_test(NAME matrix2D COMMAND matrix2d)

add_executable(matrix3d test_matrix3D.cpp)
target_link_libraries(matrix3d PRIVATE engine)
add_test(NAME matrix3D COMMAND matrix3d)

add_executable(transform2d test_transform2D.cpp)
target_link_libraries(transform2d PRIVATE engine)
add_test(NAME transform2D COMMAND transform2d)

add_executable(transform3d test_transform3D.cpp)
target_link_libraries(transform3d PRIVATE engine)
add_test(NAME transform3D COMMAND transform3d)
