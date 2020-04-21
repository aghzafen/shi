#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	bool init(const char* title, int w, int h, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
	uint64_t counter = 0L;
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;

};