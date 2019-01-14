#pragma once
#include <functional>
#include <string>
#include <SDL.h>

namespace input {
	class inputhandler {
	public:
		bool on_event(std::function<bool(std::string)> on_key);
	private:
		SDL_Event input_event;
	};
}
