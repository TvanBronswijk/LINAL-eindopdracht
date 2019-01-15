#include"game/collision/collisionbox.hpp"


math::umatrix3D<float> collisionbox::calculate_boundingbox() {
	auto mesh = _model->get_mesh();
	float biggest_x = 0.0f;
	float smallest_x = 0.0f;
	float biggest_y = 0.0f;
	float smallest_y = 0.0f;
	float biggest_z = 0.0f;
	float smallest_z = 0.0f;
	int collum = 0;

	mesh.vertices.foreach([&](auto& val) {
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

	return math::umatrix3D<float>::multidimensional_constructor<12>{ {
		{ smallest_x, smallest_x, biggest_x, biggest_x, smallest_x, smallest_x, biggest_x, biggest_x},
		{ biggest_y, smallest_y, smallest_y, biggest_y, biggest_y, smallest_y, smallest_y, biggest_y },
		{ smallest_z, smallest_z, smallest_z, smallest_z, biggest_z, biggest_z, biggest_z, biggest_z },
		{ 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f}
		} };
}