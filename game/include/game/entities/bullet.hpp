#pragma once
#include <engine/math/types.hpp>
#include <engine/rendering/3D/model.hpp>

class bullet {
public:
	bullet(rendering::rendering3d::model model, float speed) : _model(model), speed(speed) {}
	void update() {
		_model.translate({ {_model.heading.x() * speed, _model.heading.y() * speed, _model.heading.z() * speed} });
	}
	rendering::rendering3d::model& get_model() { return _model; }
private:
	rendering::rendering3d::model _model;
	float speed;
};
