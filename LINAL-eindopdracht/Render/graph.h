#pragma once
#include "color.h"
#include "renderer.h"
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
			return { center.x + (p.x * _scale), center.y + (p.y * _scale) };
		};
	public:
		graph(renderer& renderer, rectangle<int> size, float scale = 16.0f) : _re(renderer), _size(size), _scale(scale) {}
		void draw(color c = C_GRAY, bool zero_flag = true, color zero_c = C_WHITE) {
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
					.set_color(C_BLACK);
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
			_re.set_color(C_BLACK);
		}
		~graph() = default;
	};
}
