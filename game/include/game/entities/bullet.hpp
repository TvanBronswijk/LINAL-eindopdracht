#pragma once
#include <engine/math/types.hpp>
#include <engine/rendering/3D/model.hpp>
#include"game/collision/collisionbox.hpp"

class bullet {
public:
	bullet(rendering::rendering3d::model model, float speed) : _model(model),speed(speed), _collisionbox(_model) {}
	void update() {
		_model.translate({ {_model.heading.x() * speed, _model.heading.y() * speed, _model.heading.z() * speed} });
	}
	rendering::rendering3d::model& get_model() { return _model; }
	collisionbox& get_collisionbox() { return _collisionbox; }
private:
	rendering::rendering3d::model _model;
	collisionbox _collisionbox;
	float speed;
};
