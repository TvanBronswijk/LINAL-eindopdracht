#include <iostream>
#include <string>
#include <engine/input/inputhandler.hpp>
#include <engine/math.hpp>
#include <engine/render.hpp>

using namespace input;
using namespace render;
using namespace math;

static const int WIDTH = 1280;
static const int HEIGHT = 640;

void demo() {
	vector3D rotation = { 0.1f, 0.1f, 0.1f };
	matrix3D model = matrix3D::multidimensional_constructor<10>{{
		{0.0f, 0.0f, 2.0f, 1.0f, 0.0f, 1.0f, 2.0f, 0.0f, 2.0f, 1.0f},
		{2.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 1.0f},
		{0.0f, 2.0f, 0.0f, 1.0f, 2.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f},
		{0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}
	}};

	inputhandler input{};
	renderer view{WIDTH, HEIGHT};
	graph graph{view, rectangle{0, 0, WIDTH, HEIGHT}};
	try {
		while (true) {
			if (input.on_event([&](std::string key) { 
				return false; 
			})) break;
			
			view.display([&](const renderer& r, int dt) {
				graph.draw();
				graph.draw_matrix(model, colors::BLUE);
				model = rotate(model, rotation * static_cast<float>(dt));
			});
		}
	}
	catch (int e) {
		std::cout << "The program quit unexpectedly. ERROR " << std::to_string(e) << std::endl;
	}
}

int main(int argc, char* argv[])
{
	//logic
	demo();
	//memory leak detection
	_CrtDumpMemoryLeaks();
	//exit
	return 0;
}
