#pragma once
#include <engine/math/types.hpp>
#include <engine/rendering/3D/model.hpp>

class bullet {
public:
	bullet(rendering::rendering3d::model model) : _model(model) {}
	void update() {
		math::uvector3D<float> heading = _model.center();
		heading = normalize(heading);
		_model.translate({ {heading.x(), heading.y(), heading.z()} });
	}
	rendering::rendering3d::model& get_model() { return _model; }
private:
	rendering::rendering3d::model _model;
};
