#include <iostream>
#include <SDL.h>
#include "math.h"
#include "render.h"

using namespace render;
using namespace math;

static const int WIDTH = 1280;
static const int HEIGHT = 640;

void demo() {
	vector<float> v1 = { -12, -11 };
	vector<float> v2 = { 5, 15 };
	vector<float> v3 = .175 * (v1 + v2);

	renderer(WIDTH, HEIGHT)
		.display([&](renderer& r) {
			graph graph(r, rectangle<float>(0.0f, 0.0f, WIDTH, HEIGHT));
			graph.draw();
			graph.draw_vector(v1, C_RED);
			graph.draw_vector(v2, C_GREEN);
			graph.draw_vector(v3, C_BLUE);
		});
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
