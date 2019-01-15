#include "engine/rendering/3D/model.hpp"
#include <algorithm>

using namespace math;
namespace rendering::rendering3d {
	model& model::scale(uvector<float, 3> vec) {
		_scale = vec;
		return *this;
	}
	model& model::translate(uvector<float, 3> vec) {
		_mesh.vertices = math::translate(_mesh.vertices, vec);
		return *this;
	}
	model& model::rotate(uvector<float, 3> vec) {
		auto rot = math::rotate(vec);
		_mesh.vertices = rot * _mesh.vertices;
		heading = rot * heading;
		return *this;
	}
	model& model::rotate(math::uvector<float, 3> vec, math::uvector3D<float> point) {
		translate({ {-point.x(), -point.y(), -point.z()} });
		rotate(vec);
		translate({ {point.x(), point.y(), point.z()} });
		return *this;
	}
	uvector3D<float> model::center() {
		
		float minx = 999999.0f, maxx = 0.0f;
		float miny = 999999.0f, maxy = 0.0f;
		float minz = 999999.0f, maxz = 0.0f;
		for (int i = 0; i < _mesh.vertices.columns(); i++) {
			if (_mesh.vertices(0, i) > maxx)
				maxx = _mesh.vertices(0, i);
			if (_mesh.vertices(0, i) < minx)
				minx = _mesh.vertices(0, i);

			if (_mesh.vertices(1, i) > maxy)
				maxy = _mesh.vertices(1, i);
			if (_mesh.vertices(1, i) < miny)
				miny = _mesh.vertices(1, i);

			if (_mesh.vertices(2, i) > maxz)
				maxz = _mesh.vertices(2, i);
			if (_mesh.vertices(2, i) < minz)
				minz = _mesh.vertices(2, i);
		}

		float x = (minx + maxx) / 2;
		float y = (miny + maxy) / 2;
		float z = (minz + maxz) / 2;
		return {x, y, z, 1.0f};
	}
	void model::render(view<float> view, float x, float y) {
		matrix3D renderable = math::scale(_mesh.vertices, _scale);

		std::for_each(_mesh.edges.begin(), _mesh.edges.end(), [&](std::pair<size_t, size_t> pair) {
			_renderer->render_line(
				renderable(view.first, pair.first) + x,
				-renderable(view.second, pair.first) + y,
				renderable(view.first, pair.second) + x,
				-renderable(view.second, pair.second) + y);
		});
	}

	void model::render_angles(view<float> view, float x, float y) {
		auto h = center();
		_renderer->render_line(x + h[view.first], y + -h[view.second], x + heading[view.first], x + heading[view.second]);
	}
}
