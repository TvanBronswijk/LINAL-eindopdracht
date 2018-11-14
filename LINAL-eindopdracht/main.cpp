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
	vector<float> v3 = (v1 + v2) * .175;

	renderer re(WIDTH, HEIGHT);
	graph graph(rectangle<float>(0.0f, 0.0f, WIDTH, HEIGHT));
	while (!re.done) {
		re.clear();
		graph.draw(re, { 100, 100, 100 });
		graph.draw_vector(re, v1, C_RED);
		graph.draw_vector(re, v2, C_GREEN);
		graph.draw_vector(re, v3, C_BLUE);
		re.render();
		re.poll();
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
