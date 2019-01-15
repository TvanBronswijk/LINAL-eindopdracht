cmake_policy(SET CMP0048 NEW)
cmake_minimum_required (VERSION 3.8)
project(engine)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(MSVC)
	add_compile_options(/W3)
	find_package(SDL2 REQUIRED)
	find_package(SDL2_IMAGE REQUIRED)
endif(MSVC)

add_library (engine STATIC
	"src/engine/engine.cpp"
	"src/engine/input/inputhandler.cpp"
	"src/engine/rendering/renderer.cpp"
	"src/engine/rendering/graphing/graph.cpp"
	"src/engine/rendering/3D/model.cpp"
)

target_compile_features(engine PUBLIC cxx_std_17)
if (MSVC)
  set_target_properties(engine PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS true)
endif()
target_link_libraries(engine PRIVATE 
	${SDL2_LIBRARIES} 
	${SDL2_IMAGE_LIBRARIES}
)
target_include_directories(engine PUBLIC #because my include files have SDL references, SDL needs to be public
	"include"
	${SDL2_INCLUDE_DIRS}
	${SDL2_IMAGE_INCLUDE_DIRS}
)
target_include_directories(engine PRIVATE "src")


install(DIRECTORY include/engine
	DESTINATION include/engine
	FILES_MATCHING PATTERN "*.hpp"
)
install(TARGETS engine
	DESTINATION lib)
