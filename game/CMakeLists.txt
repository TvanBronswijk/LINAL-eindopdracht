cmake_minimum_required (VERSION 3.8)
project(game)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(MSVC)
	add_compile_options(/W3)
endif()

add_executable (game
	"src/game/main.cpp"
	"src/game/entities/entityfactory.cpp"
	"src/game/collision/collisionbox.cpp"
)

target_compile_features(game PUBLIC cxx_std_17)
target_link_libraries(game PRIVATE engine)
target_include_directories(game PRIVATE 
	"src"
	"include"
)