#pragma once 
#include "engine/math.hpp"

namespace rendering::rendering3d {
	struct camera {
		math::vector3D eye;
		math::vector3D lookat;
		math::vector3D up;
		camera(math::vector3D eye) : camera(eye, {0.0f, 0.0f, 0.0f, 1.0f}) {}
		camera(math::vector3D eye, math::vector3D lookat) : eye(eye), lookat(lookat), up({0.0f, 1.0f, 0.0f, 1.0f}) {}
		~camera() = default;
	};
}
