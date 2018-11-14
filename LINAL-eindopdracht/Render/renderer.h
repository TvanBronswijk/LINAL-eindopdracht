#pragma once
#include <SDL.h>
#include "color.h"

namespace render {
	class renderer {
	private:
		SDL_Window* _window;
		SDL_Renderer* _renderer;
	public:
		bool done;

		renderer(int w, int h) : _window(NULL), _renderer(NULL) {
			done = true;
			if (SDL_Init(SDL_INIT_VIDEO) == 0) {
				if (SDL_CreateWindowAndRenderer(w, h, 0, &_window, &_renderer) == 0) {
					done = false;
				}
			}
		};
		void clear(color c = C_BLACK) {
			SDL_SetRenderDrawColor(_renderer, c.r, c.g, c.b, SDL_ALPHA_OPAQUE);
			SDL_RenderClear(_renderer);
		}
		void set_color(int r, int g, int b) {
			SDL_SetRenderDrawColor(_renderer, r, g, b, SDL_ALPHA_OPAQUE);
		}
		void set_color(color c = C_WHITE) {
			SDL_SetRenderDrawColor(_renderer, c.r, c.g, c.b, SDL_ALPHA_OPAQUE);
		}
		void line(int x1, int y1, int x2, int y2) {
			SDL_RenderDrawLine(_renderer, x1, y1, x2, y2);
		}
		void render() {
			SDL_RenderPresent(_renderer);
		}
		void poll() {
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) {
					done = true;
				}
			}
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
