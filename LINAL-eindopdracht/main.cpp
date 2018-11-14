#include <iostream>
#include <SDL.h>
#include "math.h"
#include "render.h"

using namespace render;
using namespace math;

static const int WIDTH = 1280;
static const int HEIGHT = 640;

void demo() {
	vector<float> v1 = { -12.0f, -11.0f };
	vector<float> v2 = { 5.0f, 15.0f };
	vector<float> v3 = .175f * (v1 + v2);

	renderer(WIDTH, HEIGHT)
		.display([&](renderer& r) {
			graph graph(r, { 0, 0, WIDTH, HEIGHT });
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
