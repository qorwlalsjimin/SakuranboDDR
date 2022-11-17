#include "game.h"

int main() {
	int WINDOW_WIDTH = 800;
	int WINDOW_HEIGHT = 800;

	Game game(WINDOW_WIDTH, WINDOW_HEIGHT);
	game.startGame();

	return 0;
}