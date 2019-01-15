#pragma once
#include <engine/render.hpp>

class entityfactory {
public:
	entityfactory(rendering::renderer& renderer) : _renderer(&renderer) {};
	rendering::rendering3d::model create_spaceship();
	rendering::rendering3d::model create_target();
	rendering::rendering3d::model create_bullet();
	rendering::rendering3d::model create_asteroid();
private:
	rendering::renderer* _renderer;
};
