#include "engine/rendering/3D/model.hpp"
#include <algorithm>

using namespace math;
namespace rendering::rendering3d {
	model& model::scale(uvector<float, 3> vec) {
		_mesh.vertices = math::scale(_mesh.vertices, vec);
		return *this;
	}
	model& model::translate(uvector<float, 3> vec) {
		_mesh.vertices = math::translate(_mesh.vertices, vec);
		return *this;
	}
	model& model::rotate(uvector<float, 3> vec) {
		_mesh.vertices = math::rotate(_mesh.vertices, vec);
		return *this;
	}
	model& model::rotate(math::uvector<float, 3> vec, math::uvector3D<float> point) {
		translate({ {-point.x(), -point.y(), -point.z()} });
		_mesh.vertices = math::rotate(_mesh.vertices, vec);
		translate({ {-point.x(), -point.y(), -point.z()} });
		return *this;
	}
	void model::render(float x, float y) {
		std::for_each(_mesh.edges.begin(), _mesh.edges.end(), [&](std::pair<size_t, size_t> pair) {
			_renderer->render_line(
				_mesh.vertices(0, pair.first) + x, 
				-_mesh.vertices(1, pair.first) + y, 
				_mesh.vertices(0, pair.second) + x, 
				-_mesh.vertices(1, pair.second) + y);
		});
	}
}
