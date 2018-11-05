#pragma once
#include <SDL.h>

class Drawable {
protected:

public:
	Drawable() {};
	virtual void render(SDL_Renderer*& renderer) = 0;
	virtual ~Drawable() {};
};