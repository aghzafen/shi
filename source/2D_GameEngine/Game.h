#pragma once

#include "SDL.h"
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	bool init(const char* title, int x, int y, int w, int h, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;

};