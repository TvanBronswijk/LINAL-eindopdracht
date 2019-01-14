#pragma once
#include <cassert>
#include "engine/rendering/color.hpp"
#include "engine/rendering/renderer.hpp"
#include "engine/rendering/util.hpp"

#include "engine/math.hpp"
using namespace math;

namespace rendering::graphing {
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
		graph(const renderer& renderer, rectangle size, int scale = 16);
		void draw(color c = colors::GRAY, bool zero_flag = true, color zero_c = colors::BLACK);
		template<class T>
		void draw_vector(uvector2D<T> v) {
			point start = this->origin();
			point end = to_grid_point<T>({v.x(), v.y()});
			_re.render_line(start.x, start.y, end.x, end.y);
		}
		template<class T>
		void draw_vector(uvector2D<T> v, color c) {
			_re.set_color(c);
			draw_vector(v);
			_re.set_color(colors::WHITE);
		}
		template<class T, size_t Rows>
		void draw_matrix(umatrix<T, Rows> m) {
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
				_re.render_line(start.x, start.y, end.x, end.y);
			}
		}
		template<class T, size_t Rows>
		void draw_matrix(umatrix<T, Rows> m, color c) {
			_re.set_color(c);
			draw_matrix(m);
			_re.set_color(colors::WHITE);
		}

		~graph() = default;
	};
}
