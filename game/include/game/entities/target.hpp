#pragma once
#include <engine/math/types.hpp>
#include <engine/rendering/3D/model.hpp>

class target {
public:
	target(rendering::rendering3d::model model) : _model(model), grow(true), scale(1.0f) {}
	void pulse(float dt) { 
		if (scale > 1.2f) grow = false;
		if (scale < 0.8f) grow = true;
		scale += grow ? dt : -dt;
		_model.scale({ {scale, scale, scale} });
	}
	rendering::rendering3d::model& get_model() { return _model; }
private:
	bool grow;
	float scale;
	rendering::rendering3d::model _model;
};
