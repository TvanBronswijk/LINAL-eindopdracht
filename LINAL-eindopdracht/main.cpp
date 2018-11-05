#include <iostream>
#include <SDL.h>
#include "axesenderer.h"
#include "vector.h"

int main(int argc, char* argv[])
{
	Vector v1(-2, -1);
	Vector v2(5, 5);
	Vector v3 = v1 + v2;

	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;
		AxesRenderer* axes = NULL;

		if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
			SDL_bool done = SDL_FALSE;
			axes = new AxesRenderer(640, 480, 32);

			while (!done) {
				SDL_Event event;

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(renderer);

				axes->render(renderer);
				axes->draw(renderer, v1);
				axes->draw(renderer, v2);
				axes->draw(renderer, v3);

				SDL_RenderPresent(renderer);

				while (SDL_PollEvent(&event)) {
					if (event.type == SDL_QUIT) {
						done = SDL_TRUE;
					}
				}
			}
		}

		if (renderer) {
			SDL_DestroyRenderer(renderer);
		}
		if (window) {
			SDL_DestroyWindow(window);
		}
		if (axes) {
			delete axes;
		}
	}
	SDL_Quit();

	//memory leak detection
	_CrtDumpMemoryLeaks();

	//exit
	return 0;
}
