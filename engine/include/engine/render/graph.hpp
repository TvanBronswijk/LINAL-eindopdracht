#pragma once
#include <cassert>
#include "color.hpp"
#include "renderer.hpp"
#include "util.hpp"

#include "engine/math.hpp"
using namespace math;

namespace render {
	class graph {
	private:
		const renderer& _re;
		const rectangle _size;
		int _scale;

		template<class T>
		point to_grid_point(upoint<T> p) {
			point center = _size.center();
			return { 
				(center.x + ((int)(p.x * _scale))), 
				(center.y + ((int)(p.y * _scale) * -1)) 
			};
		};
		point origin() {
			return to_grid_point<int>({ 0, 0 });
		}
	public:
		graph(const renderer& renderer, rectangle size, int scale = 16) : _re(renderer), _size(size), _scale(scale) {}
		void draw(color c = colors::GRAY, bool zero_flag = true, color zero_c = colors::BLACK) {
			_re.set_color(c);
			//vertical
			for (int x = _size.x1; x < _size.x2; x += _scale)
				_re.render_line(x, _size.y1, x, _size.y2);
			//horizontal
			for (int y = _size.y1; y < _size.y2; y += _scale)
				_re.render_line(_size.x1, y, _size.x2, y);

			if (zero_flag) {
				point center = origin();
				_re
					.set_color(zero_c)
					.render_line(center.x, _size.y1, center.x, _size.y2)
					.render_line(_size.x1, center.y, _size.x2, center.y)
					.set_color(colors::WHITE);
			}
		}
		template<class T>
		void draw_vector(uvector2D<T> v) {
			point start = this->origin();
			point end = to_grid_point<T>({v.x, v.y});
			_re.render_line(start, end);
		}
		template<class T>
		void draw_vector(uvector2D<T> v, color c) {
			_re.set_color(c);
			draw_vector(v);
			_re.set_color(colors::WHITE);
		}
		template<class T>
		void draw_matrix(umatrix<T> m) {
			assert(m.rows() == 3);
			for (size_t i = 0; i < m.columns(); ++i) {
				point start, end;
				if (i == m.columns()-1) {
					start = to_grid_point<T>({ m(0, i), m(1, i) });
					end = to_grid_point<T>({ m(0, 0), m(1, 0) });
				}
				else {
					start = to_grid_point<T>({ m(0, i), m(1, i) });
					end = to_grid_point<T>({ m(0, i+1),	m(1, i+1) });
				}
				_re.render_line(start, end);
			}
		}
		template<class T>
		void draw_matrix(umatrix<T> m, color c) {
			_re.set_color(c);
			draw_matrix(m);
			_re.set_color(colors::WHITE);
		}

		~graph() = default;
	};
}
