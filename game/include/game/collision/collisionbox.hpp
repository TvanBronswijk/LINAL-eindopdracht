#pragma once
#include <engine/math/matrix3D.hpp>
#include <engine/rendering/3D/model.hpp>

class collisionbox {
public:
	collisionbox(rendering::rendering3d::model& model) : _model(&model) {};
	math::umatrix3D<float> calculate_boundingbox(rendering::rendering3d::model& model);
	bool calculate_collision(rendering::rendering3d::model& model);
private:
	rendering::rendering3d::model* _model;
};
