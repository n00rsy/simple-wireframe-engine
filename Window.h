#pragma once
#include "SDL.h"
#include <DirectXMath.h>
#include <iostream>

using namespace DirectX;

class Window
{
	
public:
	SDL_Window* window;
	SDL_Renderer* renderer;
	int pixel_width, pixel_height;

	Window(int width, int height);
	void show(XMFLOAT3 * frame);
};

