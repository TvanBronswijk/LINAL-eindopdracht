#include <iostream>
#include <string>
#include <engine/math.hpp>
#include <engine/render.hpp>

using namespace render;
using namespace math;

static const int WIDTH = 1280;
static const int HEIGHT = 640;

void demo() {
	vector3D rotation = { 3.0f, 3.0f, 9.0f };
	matrix3D model = matrix3D::multidimensional_constructor<10>{{
		{0.0f, 0.0f, 2.0f, 1.0f, 0.0f, 1.0f, 2.0f, 0.0f, 2.0f, 1.0f},
		{2.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 1.0f},
		{0.0f, 2.0f, 0.0f, 1.0f, 2.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f},
		{0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}
	}};

	matrix3D circle = matrix3D::multidimensional_constructor<3>{{
		{1.0f, 0.0f, -3.0f},
		{0.0f, 1.0f, -3.0f},
		{-3.0f, -3.0f, -9.0f},
		{0.0f, 0.0f, 0.0f}
	}};

	try {
		renderer(WIDTH, HEIGHT)
			.display([&](const renderer& r, int dt) {
			graph g{ r, rectangle{0, 0, WIDTH, HEIGHT} };
			g.draw();
			g.draw_matrix(model, colors::BLUE);
			g.draw_matrix(circle, colors::RED);
			circle = rotate(circle, rotation);
			model = rotate(model, rotation);
		});
	}
	catch (int e) {
		std::cout << "The program quit unexpectedly. ERROR " << std::to_string(e) << std::endl;
		char a;
		std::cin >> a;
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
