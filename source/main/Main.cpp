// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../2D_GameEngine/Game.h"

Game *game = nullptr;

int main(int argc, char* argv[])
{
	game = new Game();
	game->init("Shi Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600, false);
	
	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return EXIT_SUCCESS;
}


//int main(int argc, char* argv[])
//{
//    std::cout << "Hello World!\n";
//	SDL_Init(SDL_INIT_EVERYTHING);
//	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//		600, 400, SDL_WINDOW_SHOWN);
//	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
//
//	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
//	
//	SDL_RenderClear(renderer);
//
//	SDL_RenderPresent(renderer);
//
//	SDL_Delay(5000);
//
//	return EXIT_SUCCESS;
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
