cmake_policy(SET CMP0048 NEW)
cmake_minimum_required(VERSION 3.8)

# Enable testing for the project
enable_testing()

add_subdirectory(tests)


if(MSVC)
  set(SDL2_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/SDL2")
  set(SDL2_IMAGE_DIR  "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/SDL2_image")
  find_package(SDL2 REQUIRED)
  find_package(SDL2_IMAGE REQUIRED)
endif(MSVC)

set(INSTALL_DIR ${PROJECT_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${INSTALL_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${INSTALL_DIR})

add_subdirectory(engine)
add_subdirectory(game)
if(MSVC)
  list(GET SDL2_LIBRARIES 0 HEAD_SDL2_LIBRARIES)
  get_filename_component(SDL2_DLL_DIR ${HEAD_SDL2_LIBRARIES} DIRECTORY CACHE)
  list(GET SDL2_IMAGE_LIBRARIES 0 HEAD_SDL2_IMAGE_LIBRARIES)
  get_filename_component(SDL2_IMAGE_DLL_DIR ${HEAD_SDL2_IMAGE_LIBRARIES} DIRECTORY CACHE)
  file(GLOB SDL2_DLLS "${SDL2_DLL_DIR}/*.dll")
  file(GLOB SDL2_IMAGE_DLLS "${SDL2_IMAGE_DLL_DIR}/*.dll")

  add_custom_target(dependencies ALL
    COMMAND ${CMAKE_COMMAND} -E copy ${SDL2_DLLS} ${SDL2_IMAGE_DLLS} ${INSTALL_DIR})
endif(MSVC)