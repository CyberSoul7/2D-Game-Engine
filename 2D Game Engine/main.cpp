
#include "Game.h";

Game *game = nullptr;

int main(int argc, char * argv[]) {

	game = new Game();

	game->init("CyberEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	Uint64 lasttime = SDL_GetTicks();
	const double amountofticks = 60.0;
	const double ms = 1000 / amountofticks;
	double delta = 0;

	while (game->running()) {

		Uint64 now = SDL_GetTicks();
		delta += (now - lasttime) / ms;
		lasttime = now;
		while (delta >= 1) {
			game->handleEvents();
			game->update();
			delta--;
		}
		
		game->render();

	}

	game->clean();

	return 0;
}