#pragma once
#include <functional>
#include <SDL.h>
#include "color.hpp"
#include "util.hpp"

namespace rendering {
	class renderer {
	private:
		SDL_Window* _window;
		SDL_Renderer* _renderer;
		int _delta;
	public:
		renderer(int w, int h);
		const renderer& clear(int r, int g, int b) const;
		const renderer& clear(color c = colors::BLACK) const;
		const renderer& set_color(int r, int g, int b, int a = SDL_ALPHA_OPAQUE) const;
		const renderer& set_color(color c = colors::WHITE) const;
		const renderer& render_line(int x1, int y1, int x2, int y2) const;
		const renderer& present() const;
		int delta();
		renderer& display(std::function<void(int)> display_function);
		~renderer();
	};
}
