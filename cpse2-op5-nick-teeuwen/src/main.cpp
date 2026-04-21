#ifdef USE_SFML
#include "view/SFMLInterface.hpp"
#include "controller/SFMLController.hpp"
#else
#include "view/textInterface.hpp"
#include "controller/textController.hpp"
#endif
#include "model/game.hpp"
#include <iostream>


int main() {
	Game game;
// USE_SFML is gedefieneerd in de preproces waardoor we kunnen kiezen welke variant we willen per build
#ifdef USE_SFML
	std::unique_ptr<Interface> interface = std::make_unique<SFMLInterface>(game); // Gebruik SFMLInterface
	std::unique_ptr<headController> controller = std::make_unique<SFMLController>(game, *interface); // Gebruik SFMLController Pointer naar interface zodat controller ook toegang heeft tot de window
#else
	std::unique_ptr<Interface> interface = std::make_unique<textInterface>(game); // Gebruik textInterface
	std::unique_ptr<headController> controller = std::make_unique<textController>(game, *interface); // Gebruik textController Pointer naar interface zodat controller ook toegang heeft tot de window
#endif


	while (!game.isGameOver() ) {
		interface->render();
		controller->handleInput();
	}

	interface->render();
	interface->showWinner(); 
	interface->waitForClose(); // wachten tot gebruiker window sluit

	return 0;
}