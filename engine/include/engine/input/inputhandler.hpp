#pragma once
#include <functional>
#include <string>
#include <SDL.h>

namespace input {
	class inputhandler {
	public:
		bool on_event(std::function<bool(std::string)> on_key) {
			while (SDL_PollEvent(&input_event) != 0) {
				if (input_event.type == SDL_QUIT) return true;
				else if (input_event.type == SDL_KEYDOWN) return on_key(std::string(SDL_GetScancodeName(input_event.key.keysym.scancode)));
			}
			return false;
		}
	private:
		SDL_Event input_event;
	};
}
