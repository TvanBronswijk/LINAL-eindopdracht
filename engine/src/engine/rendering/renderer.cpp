#include "engine/rendering/renderer.hpp"

namespace rendering {
	renderer::renderer(int w, int h) : _window(NULL), _renderer(NULL) {
		if (!(SDL_Init(SDL_INIT_VIDEO) == 0 && SDL_CreateWindowAndRenderer(w, h, 0, &_window, &_renderer) == 0))
			throw - 1;
	};
	const renderer& renderer::clear(int r, int g, int b) const {
		SDL_SetRenderDrawColor(_renderer, r, g, b, SDL_ALPHA_OPAQUE);
		if (SDL_RenderClear(_renderer) != 0)
			throw - 1;
		return *this;
	}
	const renderer& renderer::clear(color c) const { return clear(c.r, c.g, c.b); }
	const renderer& renderer::set_color(int r, int g, int b, int a) const { SDL_SetRenderDrawColor(_renderer, r, g, b, a); return *this; }
	const renderer& renderer::set_color(color c) const { return set_color(c.r, c.g, c.b, c.a); }
	const renderer& renderer::render_line(int x1, int y1, int x2, int y2) const { if (SDL_RenderDrawLine(_renderer, x1, y1, x2, y2) != 0) throw - 1; return *this; }
	const renderer& renderer::present() const { SDL_RenderPresent(_renderer); return *this; }
	int renderer::delta() {
		int now = SDL_GetTicks();
		int delta = now - _delta;
		_delta = now;
		return delta;
	}
	renderer& renderer::display(std::function<void(int)> display_function) {
		clear();
		display_function(delta());
		present();
		return *this;
	}

	renderer::~renderer() {
		if (_renderer) {
			SDL_DestroyRenderer(_renderer);
		}
		if (_window) {
			SDL_DestroyWindow(_window);
		}
		SDL_Quit();
	}
}
