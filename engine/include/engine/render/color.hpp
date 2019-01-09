#pragma once

namespace render {
	struct color {
		int r, g, b;
		color(int r, int g, int b) : r(r), g(g), b(b) {}
		~color() = default;
	};

	namespace colors {
		static const color WHITE = { 255, 255, 255 };
		static const color GRAY = { 180, 180, 180 };
		static const color BLACK = { 0, 0, 0 };
		static const color RED = { 255, 0, 0 };
		static const color GREEN = { 0, 255, 0 };
		static const color BLUE = { 0, 0, 255 };
	}
}

