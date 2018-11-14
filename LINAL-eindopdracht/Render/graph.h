#pragma once
#include "color.h"
#include "renderer.h"
#include "..\math.h"
using namespace math;

namespace render {
	class graph {
	private:
		float _grid;
		rectangle<float> _size;

		point<float> to_grid_point(point<float> p) {
			point<float> center = _size.center();
			return { center.x + (p.x * _grid), center.y + (p.y * _grid) };
		};
	public:
		graph(rectangle<float> size, float grid = 16.0f) : _size(size), _grid(grid) {}
		void draw(renderer& r, bool zero_flag = true) {
			//vertical
			for (int x = _size.x1; x < _size.x2; x += _grid)
				r.line(x, _size.y1, x, _size.y2);
			//horizontal
			for (int y = _size.y1; y < _size.y2; y += _grid)
				r.line(_size.x1, y, _size.x2, y);

			if (zero_flag) {
				point<float> center = _size.center();
				r.set_color(C_WHITE);
				r.line(center.x, _size.y1, center.x, _size.y2);
				r.line(_size.x1, center.y, _size.x2, center.y);
				r.set_color(C_BLACK);
			}
		}
		void draw(renderer& r, color c, bool zero_flag = true) {
			r.set_color(c);
			draw(r);
			r.set_color(C_BLACK);
		}
		void draw_vector(renderer& r, vector<float> v) {
			point<float> center = _size.center();
			point<float> end = to_grid_point({v.x, v.y});
			r.line(center.x, center.y, end.x, end.y);
		}
		void draw_vector(renderer& r, vector<float> v, color c) {
			r.set_color(c);
			draw_vector(r, v);
			r.set_color(C_BLACK);
		}
		~graph() = default;
	};
}
