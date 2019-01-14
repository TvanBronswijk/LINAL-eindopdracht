#include <iostream>
#include <string>
#include <engine/input/inputhandler.hpp>
#include <engine/math.hpp>
#include <engine/render.hpp>

using namespace input;
using namespace rendering;
using namespace rendering::rendering3d;
using namespace math;

static const int WIDTH = 1280;
static const int HEIGHT = 640;

void demo() {
	mesh model{
		matrix3D::multidimensional_constructor<4>{{
			{0.0f, 50.0f, 25.0f, 25.0f},
			{0.0f, 0.0f, 50.0f, 25.0f},
			{0.0f, 0.0f, 0.0f, 10.f},
			{1.0f, 1.0f, 1.0f, 1.0f}
		}},
		{
			{0, 1},
			{1, 2},
			{2, 0},
			{0, 3},
			{1, 3},
			{2, 3}
		}
	};

	inputhandler input{};
	renderer view{ WIDTH, HEIGHT };
	graphing::graph graph{ view, rectangle{0, 0, WIDTH, HEIGHT} };
	try {
		while (true) {
			if (input.on_event([&](std::string key) {
				return false;
			})) break;

			view.display([&](int dt) {
				view.set_color(colors::RED);
				model.render(view);
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
