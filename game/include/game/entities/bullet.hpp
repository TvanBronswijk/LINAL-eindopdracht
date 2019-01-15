#pragma once
#include <engine/math/types.hpp>
#include <engine/rendering/3D/model.hpp>
#include"game/collision/collisionbox.hpp"

class bullet {
public:
	bullet(rendering::rendering3d::model model) : _model(model), _collisionbox(_model) {}
	void update() {
		math::uvector3D<float> heading = _model.center();
		heading = normalize(heading);
		_model.translate({ {heading.x(), heading.y(), heading.z()} });
	}
	rendering::rendering3d::model& get_model() { return _model; }
private:
	rendering::rendering3d::model _model;
	collisionbox _collisionbox;
};
