#include "engine/rendering/graphing/graph.hpp"

namespace rendering::graphing {
	graph::graph(const renderer& renderer, rectangle size, int scale) : _re(renderer), _size(size), _scale(scale) {}
	void graph::draw(color c, bool zero_flag, color zero_c) {
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
}
