#include "Window.h"

	Window::Window(int width, int height) {
			SDL_Init(SDL_INIT_VIDEO);
			window = NULL;
			renderer = NULL;
			window = SDL_CreateWindow
			("SDL Snake",
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				width, height,
				SDL_WINDOW_OPENGL);

			renderer = SDL_CreateRenderer(window, -1, 0);
			pixel_width = width;
			pixel_height = height;
}

	void Window::show(XMFLOAT3* frame) {

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
		SDL_RenderClear(renderer);
		int size = pixel_width * pixel_height;

		for (int i = 0; i < size; i++) {
			SDL_SetRenderDrawColor(renderer, frame[i].x*255, frame[i].y * 255,frame[i].z * 255,255);
			SDL_RenderDrawPoint(renderer,i % pixel_width, i / pixel_width);
		}
		SDL_RenderPresent(renderer);
	}
