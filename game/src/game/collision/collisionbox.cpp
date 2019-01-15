#include"game/collision/collisionbox.hpp"


math::umatrix3D<float> collisionbox::calculate_boundingbox(rendering::rendering3d::model& model) {
	auto center = model.center();
	float biggest_x = center.x();
	float smallest_x = center.x();
	float biggest_y = center.y();
	float smallest_y = center.y();
	float biggest_z = center.z();
	float smallest_z = center.z();
	int collum = 0;

	model.get_mesh().vertices.foreach([&](auto& val) {
		if (collum == 5) collum = 0;
		switch (collum) {
		case 1:
			if (val > biggest_x) biggest_x = val;
			if (val < smallest_x) smallest_x = val;
			break;
		case 2:
			if (val > biggest_y) biggest_y = val;
			if (val < smallest_y) smallest_y = val;
			break;
		case 3:
			if (val > biggest_x) biggest_z = val;
			if (val < smallest_x) smallest_z = val;
			break;
		case 4:
			break;
		}
		collum++;
	});

	return math::umatrix3D<float>::multidimensional_constructor<2>{ {
		{ smallest_x,biggest_x},
		{ biggest_y,smallest_y},
		{ smallest_z,biggest_z},
		{ 1.0f, 1.0f}
		} };
}


bool collisionbox::calculate_collision(rendering::rendering3d::model& target_model) {
	bool collide = false;
	auto source_boundingbox = calculate_boundingbox(*_model);
	auto target_boundingbox = calculate_boundingbox(target_model);
	
	for (int i = 0; i < 2; i++) {
		if (source_boundingbox.at(0, 0) < target_boundingbox.at(0, i) && source_boundingbox.at(0, 1) > target_boundingbox.at(0, i)) {
			if (source_boundingbox.at(1, 0) < target_boundingbox.at(1, i) && source_boundingbox.at(1, 1) > target_boundingbox.at(1, i)) {
				if (source_boundingbox.at(2, 0) < target_boundingbox.at(2, i) && source_boundingbox.at(2, 1) > target_boundingbox.at(2, i)) {
					collide = true;
				}
			}
		}
	}

	return collide;
}