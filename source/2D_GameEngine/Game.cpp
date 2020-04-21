#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;

Game::Game()
{

}

Game::~Game()
{

}

bool Game::init(const char* title, int w, int h, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if ( SDL_Init(SDL_INIT_EVERYTHING) == 0 )
	{
#ifdef _DEBUG
		std::cout << "SDL Layer Initialized." << std::endl;
#endif // _DEBUG
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			w, h, flags);
		if (window)
		{
#ifdef _DEBUG
			std::cout << "Window Created." << std::endl;
#endif // _DEBUG
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer)
			{
#ifdef _DEBUG
				std::cout << "Renderer Created." << std::endl;
#endif // _DEBUG
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
				isRunning = true;
			}
		}
	}
	else
	{
		isRunning = false;
	}

	player = new GameObject("assets/pipi.png", renderer, 0, 0);

	return isRunning;
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Game::update()
{
	++counter;
#ifdef _DEBUG
	std::cout << "counter: " << counter << std::endl;
#endif // _DEBUG

	player->update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	player->render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
#ifdef _DEBUG
	std::cout << "Pipeline Cleaned." << std::endl;
#endif // _DEBUG

}
