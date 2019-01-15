#pragma once
#include <engine/math/types.hpp>
#include <engine/rendering/3D/model.hpp>
#include"game/collision/collisionbox.hpp"

class asteroid {
public:
	asteroid(rendering::rendering3d::model model) : _model(model), _collisionbox(_model) {}
	void update() {
		//_model.rotate({ { 0.5f, 0.5f, 0.0f } }, _model.center());
	}
	rendering::rendering3d::model& get_model() { return _model; }
	collisionbox& get_collisionbox() { return _collisionbox; }
private:
	rendering::rendering3d::model _model;
	collisionbox _collisionbox;
};
#pragma once
