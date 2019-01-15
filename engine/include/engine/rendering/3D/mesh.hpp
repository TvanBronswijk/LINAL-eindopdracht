#pragma once
#include <vector>
#include "engine/math/matrix3D.hpp"
#include "engine/rendering/renderer.hpp"

namespace rendering::rendering3d {
	struct mesh {
		mesh(math::umatrix3D<float> vertices, std::vector<std::pair<size_t, size_t>> edges) : vertices(vertices), edges(edges) {};
		math::umatrix3D<float> vertices;
		std::vector<std::pair<size_t, size_t>> edges;
	};
}
