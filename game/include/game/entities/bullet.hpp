#pragma once
#include <engine/math/types.hpp>
#include <engine/rendering/3D/model.hpp>
#include"game/collision/collisionbox.hpp"

class bullet {
public:
	bullet(rendering::rendering3d::model model) : _model(model), _collisionbox(_model) {}
	void update() {
		_model.translate({ {_model.heading.x(), _model.heading.y(), _model.heading.z()} });
	}
	rendering::rendering3d::model& get_model() { return _model; }
	collisionbox& get_collisionbox() { return _collisionbox; }
private:
	rendering::rendering3d::model _model;
	collisionbox _collisionbox;
};
