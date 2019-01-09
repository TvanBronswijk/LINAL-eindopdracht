#pragma once

namespace render {
	struct color {
		int r, g, b, a;
		color() : r(0), g(0), b(0), a(255) {}
		color(int r, int g, int b) : r(r), g(g), b(b), a(255) {}
		color(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {}
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

