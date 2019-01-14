#include "engine/rendering/3D/mesh.hpp"
#include <algorithm>

namespace rendering::rendering3d {
	mesh::mesh(math::matrix3D vertices, std::vector<std::pair<size_t, size_t>> edges) : _vertices(vertices), _edges(edges) { }
	
	void mesh::render(const renderer& r) {
		std::for_each(_edges.begin(), _edges.end(), [&](auto& pair) {
			r.render_line(_vertices(0, pair.first) + 100, -_vertices(1, pair.first) + 100, _vertices(0, pair.second) + 100, -_vertices(1, pair.second) + 100);
		});
	}
}
