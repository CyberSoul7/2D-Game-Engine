
#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

#include "ECS.h"
#include "Components.h"

GameObject* player;

EntityManager manager;
auto& newPlayer(manager.addEntity());

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
	
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		std::cout << "Subsystems Initialized!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;

	}
	else {
		isRunning = false;
	}

	player = new GameObject("assets/player.png", 0, 0);
	player->setVelX(1);

	newPlayer.addComponent<PositionComponent>();

}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()	{
	player->update();
	manager.update();
	std::cout << newPlayer.getComponent<PositionComponent>().x() << ", " <<
		newPlayer.getComponent<PositionComponent>().y() << std::endl;
}

void Game::render() {
	SDL_RenderClear(renderer);
	//Start Rendering

	player->render(renderer);
	manager.draw();

	//Stop Rendering
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}