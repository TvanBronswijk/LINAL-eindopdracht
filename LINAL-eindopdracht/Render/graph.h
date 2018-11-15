#pragma once
#include <cassert>
#include "color.h"
#include "renderer.h"
#include "util.h"

#include "..\math.h"
using namespace math;

namespace render {
	class graph {
	private:
		renderer& _re;
		rectangle<int> _size;
		float _scale;

		point<float> to_grid_point(point<float> p) {
			point<int> center = _size.center();
			return { (center.x + (p.x * _scale)), (center.y + (-1* p.y * _scale)) };
		};
	public:
		graph(renderer& renderer, rectangle<int> size, float scale = 16.0f) : _re(renderer), _size(size), _scale(scale) {}
		void draw(color c = C_GRAY, bool zero_flag = true, color zero_c = C_BLACK) {
			_re.set_color(c);
			//vertical
			for (int x = _size.x1; x < _size.x2; x += _scale)
				_re.render_line(x, _size.y1, x, _size.y2);
			//horizontal
			for (int y = _size.y1; y < _size.y2; y += _scale)
				_re.render_line(_size.x1, y, _size.x2, y);

			if (zero_flag) {
				point<float> center = to_grid_point({ 0.0f, 0.0f });
				_re
					.set_color(zero_c)
					.render_line(center.x, _size.y1, center.x, _size.y2)
					.render_line(_size.x1, center.y, _size.x2, center.y)
					.set_color(C_WHITE);
			}
		}
		void draw_vector(vector<float> v) {
			point<float> center = to_grid_point({0.0f, 0.0f});
			point<float> end = to_grid_point({v.x, v.y});
			_re.render_line(center.x, center.y, end.x, end.y);
		}
		void draw_vector(vector<float> v, color c) {
			_re.set_color(c);
			draw_vector(v);
			_re.set_color(C_WHITE);
		}
		void draw_matrix(matrix<float> m) {
			assert(m.rows() == 2);
			for (size_t i = 0; i < m.columns(); ++i) {
				if (i <= 0) {
					auto point_a = to_grid_point({ m(0, i), m(1, i) });
					auto point_b = to_grid_point({ m(0, m.columns() - 1), m(1, m.columns() -1 ) });
					_re.render_line(point_a.x, point_a.y, point_b.x, point_b.y);
				}
				else if (i < m.columns()-1) {
					auto point_a = to_grid_point({ m(0, i), m(1, i) });
					auto point_b = to_grid_point({ m(0, 0), m(1, 0) });
					_re.render_line(point_a.x, point_a.y, point_b.x, point_b.y);
				}
				else {
					auto point_a = to_grid_point({ m(0, i - 1), m(1, i - 1) });
					auto point_b = to_grid_point({ m(0, i),		m(1, i) });
					_re.render_line(point_a.x, point_a.y, point_b.x, point_b.y);
				}
			}
		}

		void draw_matrix(matrix<float> m, color c) {
			_re.set_color(c);
			draw_matrix(m);
			_re.set_color(C_WHITE);
		}

		~graph() = default;
	};
}
