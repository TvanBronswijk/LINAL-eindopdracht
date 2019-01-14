#pragma once
#include <functional>
#include <SDL.h>
#include "color.hpp"
#include "util.hpp"

namespace render {
	class renderer {
	private:
		SDL_Window* _window;
		SDL_Renderer* _renderer;
		int _delta;
	public:
		renderer(int w, int h) : _window(NULL), _renderer(NULL) {
			if (!(SDL_Init(SDL_INIT_VIDEO) == 0 && SDL_CreateWindowAndRenderer(w, h, 0, &_window, &_renderer) == 0))
				throw - 1;
		};

		const renderer& clear(int r, int g, int b) const {
			SDL_SetRenderDrawColor(_renderer, r, g, b, SDL_ALPHA_OPAQUE);
			if (SDL_RenderClear(_renderer) != 0)
				throw - 1;
			return *this;
		}
		const renderer& clear(color c = colors::WHITE) const {
			return clear(c.r, c.g, c.b);
		}
		const renderer& set_color(int r, int g, int b, int a = SDL_ALPHA_OPAQUE) const {
			SDL_SetRenderDrawColor(_renderer, r, g, b, a);
			return *this;
		}
		const renderer& set_color(color c = colors::BLACK) const {
			return set_color(c.r, c.g, c.b, c.a);
		}
		const renderer& render_line(int x1, int y1, int x2, int y2) const {
			if (SDL_RenderDrawLine(_renderer, x1, y1, x2, y2) != 0)
				throw - 1;
			return *this;
		}
		template<class T>
		const renderer& render_line(upoint<T> origin, upoint<T> end) const {
			return render_line(origin.x, origin.y, end.x, end.y);
		}
		const renderer& present() const {
			SDL_RenderPresent(_renderer);
			return *this;
		}
		int delta() {
			int now = SDL_GetTicks();
			int delta = now - _delta;
			_delta = now;
			return delta;
		}
		renderer& display(std::function<void(const renderer&, int)> display_function) {
			clear();
			display_function(*this, delta());
			present();
			return *this;
		}

		~renderer() {
			if (_renderer) {
				SDL_DestroyRenderer(_renderer);
			}
			if (_window) {
				SDL_DestroyWindow(_window);
			}
			SDL_Quit();
		}
	};
}
