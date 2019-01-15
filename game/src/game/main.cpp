#include <iostream>
#include <string>
#include <engine/input/inputhandler.hpp>
#include <engine/math.hpp>
#include <engine/render.hpp>
#include "game/entities/entityfactory.hpp"
#include "game/entities/spaceship.hpp"

using namespace input;
using namespace rendering;
using namespace rendering::rendering3d;
using namespace math;

static const int WIDTH = 1280;
static const int HEIGHT = 640;

void demo() {
	renderer view{ WIDTH, HEIGHT };
	entityfactory factory{ view };
	spaceship ship{ factory.create_spaceship() };

	inputhandler input{};
	rendering3d::view<float> view_angle = rendering3d::view<float>::xy;
	try {
		while (true) {
			if (input.on_event([&](std::string key) {
				if (key == "W") {
					ship.pitch(-1.0f);
				}
				if (key == "S") {
					ship.pitch(1.0f);
				}
				if (key == "A") {
					ship.yaw(-1.0f);
				}
				if (key == "D") {
					ship.yaw(1.0f);
				}
				if (key == "Q") {
					ship.roll(-1.0f);
				}
				if (key == "E") {
					ship.roll(1.0f);
				}
				if (key == "Space") {
				}
				if (key == "1") {
					view_angle = rendering3d::view<float>::xy;
				}
				if (key == "2") {
					view_angle = rendering3d::view<float>::yz;
				}
				if (key == "3") {
					view_angle = rendering3d::view<float>::xz;
				}
				return false;
			})) break;

			view.display([&](int dt) {
				view.set_color(colors::RED);
				ship.get_model().render(view_angle, WIDTH / 2.0f, HEIGHT / 2.0f);
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
