#pragma once
#include "drawable.h"
#include "vector.h"

class AxesRenderer : public Drawable {
private:
	size_t w, h, interval;
public:
	AxesRenderer(size_t w, size_t h, size_t interval);
	void render(SDL_Renderer*& renderer) override;
	void draw(SDL_Renderer*& renderer, Vector v);
};