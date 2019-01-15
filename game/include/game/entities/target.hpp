#pragma once
#include <engine/math/types.hpp>
#include <engine/rendering/3D/model.hpp>
#include"game/collision/collisionbox.hpp"

class target {
public:
	target(rendering::rendering3d::model model) : _model(model), grow(true), scale(1.0f), direction(false), counteract(false), timer(0.0f), _collisionbox(_model) {}
	void pulse(float dt) { 
		timer += dt;
		if (timer > 40.0f) {
			if (direction) {
				scale -= 0.01f;
				if (scale <= 0.9f) { direction = false;
				if (counteract) { counteract = false; }
				else { counteract = true; }
				}
			}
			else {
				scale += 0.01f;
				if (counteract) {
					if (scale >= 1.1f) { direction = true; }
				}
				else {
					if (scale >= 1.11f) { direction = true; }
				}
			}
			_model.scale({ {scale, scale, scale} });
			timer = 0.0f;
		}
	}
	rendering::rendering3d::model& get_model() { return _model; }
	collisionbox& get_collisionbox() { return _collisionbox; }
private:
	bool grow;
	float timer;
	bool direction;
	bool counteract;
	float scale;
	rendering::rendering3d::model _model;
	collisionbox _collisionbox;
};
