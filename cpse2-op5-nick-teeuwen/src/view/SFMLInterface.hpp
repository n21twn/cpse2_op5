#pragma once
#include "Interface.hpp"
#include "../model/game.hpp"
#include <SFML/Graphics.hpp>

class SFMLInterface : public Interface {
public: 
	SFMLInterface(Game& game) : game_(game), window_(sf::VideoMode(600, 600), "Tic-Tac-Toe") {
		font_.loadFromFile("C:/Windows/Fonts/arial.ttf");// gebruik standaard font van windows

	}
	// public accessor for the window so other modules can use it without accessing private members

	void render() override;
	void showWinner() override;
	void showMessage(std::string message) override;
	void waitForClose() override;
	virtual InputResult getPlayerInput(int& row, int& col) override;

private:
	Game& game_; 
	sf::RenderWindow window_;
	sf::Font font_;
	std::string message_;

	void drawX(int row, int col);
	void drawO(int row, int col);
};