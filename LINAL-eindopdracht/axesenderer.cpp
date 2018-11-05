#include "axesenderer.h"

AxesRenderer::AxesRenderer(size_t w, size_t h, size_t interval)
{
	this->w = w;
	this->h = h;
	this->interval = interval;
}

void AxesRenderer::render(SDL_Renderer*& renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	for(int i = 0; i < h; i += interval)
		SDL_RenderDrawLine(renderer, 0, i, w, i);
	for (int i = 0; i < w; i += interval)
		SDL_RenderDrawLine(renderer, i, 0, i, h);
}

void AxesRenderer::draw(SDL_Renderer*& renderer, Vector v)
{
	Vector origin(w / 2 / interval, h / 2 / interval);
	Vector tail = origin + v;

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, origin.x * interval, origin.y * interval, tail.x * interval, tail.y * interval);
}
