#pragma once
#include <vector>
#include "engine/math.hpp"
#include "engine/rendering/renderer.hpp"

namespace rendering::rendering3d {
	class mesh {
	public:
		mesh(math::matrix3D, std::vector<std::pair<size_t, size_t>>);
		void render(const renderer&);
	private:
		math::matrix3D _vertices;
		std::vector<std::pair<size_t, size_t>> _edges;
	};
}
