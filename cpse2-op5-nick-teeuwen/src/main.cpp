#include "view/textInterface.hpp"
#include "controller/textController.hpp"
#include "view/SFMLInterface.hpp"
#include "controller/SFMLController.hpp"
#include "model/game.hpp"

int main() {
	Game game;

	std::unique_ptr<Interface> interface = std::make_unique<SFMLInterface>(game); // Gebruik SFMLInterface
	std::unique_ptr<headController> controller = std::make_unique<SFMLController>(game, *interface); // Gebruik SFMLController Pointer naar interface zodat controller ook toegang heeft tot de window
	//std::unique_ptr<Interface> interface = std::make_unique<textInterface>(game); // Gebruik textInterface
	//std::unique_ptr<headController> controller = std::make_unique<textController>(game, *interface); // Gebruik textController Pointer naar interface zodat controller ook toegang heeft tot de window



	while (!game.isGameOver()) {
		interface->render();
		controller->handleInput();
	}

	interface->render();
	interface->showWinner(); 
	interface->waitForClose(); // wachten tot gebruiker window sluit

	return 0;
}