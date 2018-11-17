#include <iostream>
#include <SDL.h>
#include "math.h"
#include "render.h"

using namespace render;
using namespace math;

static const int WIDTH = 1280;
static const int HEIGHT = 640;

void demo() {
	vector2d v1 = { -12.0f, -11.0f };
	vector2d v2 = { 5.0f, 15.0f };
	vector2d v3 = v1 + v2;

	matrix m1 = {{
		{5.0f, 5.0f, 10.0f, 10.0f, 7.5f},
		{5.0f, 10.0f, 10.0f, 5.0f, 2.5f}
	}};

	try {
		renderer(WIDTH, HEIGHT)
			.display([&](const renderer& r) {
			graph graph(r, { 0, 0, WIDTH, HEIGHT });
			graph.draw();
			graph.draw_vector(v1, colors::RED);
			graph.draw_vector(v2, colors::GREEN);
			graph.draw_vector(v3, colors::BLUE);
			graph.draw_matrix(m1, colors::RED);
		});
	}
	catch (int e) {
		std::cout << "The program quit unexpectedly." << std::endl;
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
