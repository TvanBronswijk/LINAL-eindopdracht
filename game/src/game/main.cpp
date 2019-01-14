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
	uvector<float, 3> rotation = { { 0.1f, 0.2f, 0.1f } };
	vector3D vec{};
	matrix3D model = matrix3D::multidimensional_constructor<10>{ {
		{0.0f, 0.0f, 2.0f, 1.0f, 0.0f, 1.0f, 2.0f, 0.0f, 2.0f, 1.0f},
		{2.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 1.0f},
		{0.0f, 2.0f, 0.0f, 1.0f, 2.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f},
		{1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f}
	} };

	model = translate(model, { {-1.0f, -1.0f, -1.0f} });
	model = scale(model, { { 3.0f, 3.0f, 3.0f } });

	inputhandler input{};
	renderer view{ WIDTH, HEIGHT };
	graph graph{ view, rectangle{0, 0, WIDTH, HEIGHT} };
	try {
		while (true) {
			if (input.on_event([&](std::string key) {
				return false;
			})) break;

			view.display([&](int dt) {
				graph.draw();
				graph.draw_vector(vector2D(vec.x(), vec.y(), vec.w()), colors::GREEN);
				graph.draw_matrix(model, colors::BLUE);
				model = rotate(model, rotation);
			});

			vec = *static_cast<vector3D*>(&(model * vector3D{ 1.0f, 1.0f, 1.0f, 1.0f }));
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
