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

	matrix<float> m1 = { 2, 4 };
	m1(0, 0) = 5.0f;
	m1(1, 0) = 5.0f;
	m1(0, 1) = 5.0f;
	m1(1, 1) = 10.0f;
	m1(0, 2) = 10.0f;
	m1(1, 2) = 10.0f;
	m1(0, 3) = 10.0f;
	m1(1, 3) = 5.0f;


	renderer(WIDTH, HEIGHT)
		.display([&](renderer& r) {
			graph graph(r, { 0, 0, WIDTH, HEIGHT });
			graph.draw();
			graph.draw_vector(v1, C_RED);
			graph.draw_vector(v2, C_GREEN);
			graph.draw_vector(v3, C_BLUE);
			graph.draw_matrix(m1, C_RED);
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
