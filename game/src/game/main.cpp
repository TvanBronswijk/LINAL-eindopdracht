#include <iostream>
#include <string>
#include <engine/math.hpp>
#include <engine/render.hpp>

using namespace render;
using namespace math;

static const int WIDTH = 1280;
static const int HEIGHT = 640;

void demo() {
	vector2D v1 = { -12.0f, -11.0f };

	matrix2D m1 = matrix2D::multidimensional_constructor<5>{{
		{0.0f,  0.0f, 5.0f, 5.0f, 2.5f},
		{0.0f,  5.0f, 5.0f, 0.0f, 2.5f},
		{1.0f,  1.0f,  1.0f,  1.0f, 1.0f}
	}};

	try {
		renderer(WIDTH, HEIGHT)
			.display([&](const renderer& r, int dt) {
			graph graph(r, { 0, 0, WIDTH, HEIGHT });
			graph.draw();
			graph.draw_vector(v1, colors::RED);
			graph.draw_matrix(m1, colors::BLUE);
			m1 = rotate(m1, ((float)dt / 10.0f));
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
