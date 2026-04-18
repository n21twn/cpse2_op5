#include "view/textInterface.hpp"
#include "controller/textController.hpp"
#include "model/game.hpp"

int main() {
	Game game;
	textInterface interface(game);
	textController controller(game, interface);

	while(!game.isGameOver()) {
		interface.render();
		controller.handleInput();
	}
	interface.render();
	interface.showWinner();
	return 0;
}