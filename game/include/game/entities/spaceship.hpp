#pragma once
#include <engine/rendering/3D/model.hpp>
#include"game/collision/collisionbox.hpp"

class spaceship {
public:
	float speed{ 0.0f };
	spaceship(rendering::rendering3d::model model) : _model(model), max_speed(1.0f), _collisionbox(_model) {}
	spaceship(rendering::rendering3d::model model, float max_speed) : _model(model), max_speed(max_speed), _collisionbox(_model) {}
	void pitch(float f) { rotate(f, 0.0f, 0.0f); }
	void yaw(float f) { rotate(0.0f, f, 0.0f); }
	void roll(float f) { rotate(0.0f, 0.0f, f); }
	void move(float f) { 
		if (speed < max_speed)
			speed += f;
	}
	void update() {
		if (speed > 0.0f) {
			translate(_model.heading.x() * speed, _model.heading.y() * speed, _model.heading.z() * speed);
			speed -= max_speed / 256.0f;
		}
	}
	rendering::rendering3d::model& get_model() { return _model; }
	collisionbox& get_collisionbox() { return _collisionbox; }
private:
	void translate(float x, float y, float z) {
		_model.translate({ {x, y, z} });
	}
	void rotate(float x, float y, float z) {
		_model.rotate({ {x, y, z} }, _model.center());
	}
	float max_speed;
	rendering::rendering3d::model _model;
	collisionbox _collisionbox;

};
