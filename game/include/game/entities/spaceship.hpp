#pragma once
#include <engine/rendering/3D/model.hpp>

class spaceship {
public:
	spaceship(rendering::rendering3d::model model) : _model(model) {}
	void pitch(float f) { rotate(f, 0.0f, 0.0f); }
	void yaw(float f) { rotate(0.0f, f, 0.0f); }
	void roll(float f) { rotate(0.0f, 0.0f, f); }
	void move(float f) { translate(0.0f, 0.0f, 0.0f); }
	rendering::rendering3d::model& get_model() { return _model; }
private:
	void translate(float x, float y, float z) {
		_model.translate({ {x, y, z} });
	}
	void rotate(float x, float y, float z) {
		_model.rotate({ {x, y, z} }, _model.center());
	}
	rendering::rendering3d::model _model;
};
