#pragma once

namespace render {
	struct color {
		int r, g, b;
		color(int r, int g, int b) : r(r), g(g), b(b) {}
		~color() = default;
	};

	static const color C_WHITE = { 255, 255, 255 };
	static const color C_GRAY = { 127, 127, 127 };
	static const color C_BLACK = { 0, 0, 0 };
	static const color C_RED = { 255, 0, 0 };
	static const color C_GREEN = { 0, 255, 0 };
	static const color C_BLUE = { 0, 0, 255 };
}

