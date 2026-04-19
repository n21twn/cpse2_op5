#pragma once
#include "Interface.hpp"
#include "../model/game.hpp"
#include <SFML/Graphics.hpp>

class SFMLInterface : public Interface {
public: 
	SFMLInterface(Game& game) : game_(game), window_(sf::RenderWindow(sf::VideoMode(600, 600), "Tic-Tac-Toe")) {}

	void render() override;
	void showWinner() override;
	void showMessage(std::string message) override;

private:
	Game& game_; 
	sf::RenderWindow window_;
	sf::Font font_;
};