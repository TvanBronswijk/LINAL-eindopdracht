#include <iostream>
#include <string>
#include <engine/input/inputhandler.hpp>
#include <engine/math.hpp>
#include <engine/render.hpp>
#include "game/entities/entityfactory.hpp"
#include "game/entities/spaceship.hpp"
#include "game/entities/target.hpp"
#include "game/entities/bullet.hpp"

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
	target diamond{ factory.create_target() };
	diamond.get_model().translate({ {200.0f, 200.0f, 300.0f} });

	auto h = ship.get_model().center();
	bullet shot{ factory.create_bullet({{h.x(), h.y(), h.z()}}) };


	inputhandler input{};
	rendering3d::view<float> view_angle = rendering3d::view<float>::xy;
	try {
		while (true) {
			if (input.on_event([&](std::string key) {
				if (key == "W") ship.pitch(-1.0f);
				else if (key == "S") ship.pitch(1.0f);
				else if (key == "A") ship.yaw(-1.0f);
				else if (key == "D") ship.yaw(1.0f);
				else if (key == "Q") ship.roll(-1.0f);
				else if (key == "E") ship.roll(1.0f);
				else if (key == "Left Shift") ship.move(1.0f);
				else if (key == "Space") shot.update();
				else if (key == "1") view_angle = rendering3d::view<float>::xy;
				else if (key == "2") view_angle = rendering3d::view<float>::zy;
				else if (key == "3") view_angle = rendering3d::view<float>::xz;
				else if (key == "Escape") return true;
				return false;
			})) break;

			view.display([&](int dt) {
				view.set_color(colors::RED);
				ship.get_model().render(view_angle, WIDTH / 2.0f, HEIGHT / 2.0f);
				diamond.get_model().render(view_angle, WIDTH / 2.0f, HEIGHT / 2.0f);
				shot.get_model().render(view_angle, WIDTH / 2.0f, HEIGHT / 2.0f);
				view.set_color(colors::BLUE);
				ship.get_model().render_angles(view_angle, WIDTH / 2.0f, HEIGHT / 2.0f);
				diamond.pulse(dt);
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
