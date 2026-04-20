#include "SFMLInterface.hpp"
#include <iostream>

InputResult SFMLInterface::getPlayerInput(int& row, int& col) {
	sf::Event event;
	while (window_.waitEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window_.close();
			return InputResult::Invalid;
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			row = event.mouseButton.y / 200;
			col = event.mouseButton.x / 200;
			if (row >= 0 && row < 3 && col >= 0 && col < 3) {
				return InputResult::Move;
			}
			return InputResult::Invalid;
		}
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::U) {
				return InputResult::Undo;
			}
		}
	}
	return InputResult::Invalid;
}

void SFMLInterface::render() {
	window_.clear();
	for (int r = 0; r < 3; ++r) {
		for (int c = 0; c < 3; ++c) {
			sf::RectangleShape cell(sf::Vector2f(200.f, 200.f));
			cell.setPosition(c * 200.f, r * 200.f);
			cell.setOutlineThickness(2.f);
			cell.setOutlineColor(sf::Color::White);
			cell.setFillColor(sf::Color::Black);
			window_.draw(cell);
			Player p = game_.getCell(r, c);
			if (p == Player::X) { 
				drawX(r, c);
			}
			else if (p == Player::O) { 
				drawO(r, c); 
			}
			
		}

	}
	// Tekst voor berichten onderaan het scherm 
	sf::Text text(message_, font_, 32);
	text.setFillColor(sf::Color::White);
	text.setPosition(10.f, 610.f); // Plaats het bericht in het midden van het venster
	window_.draw(text);
	window_.display();
}

void SFMLInterface::drawO(int row, int col) { 
	sf::CircleShape circle(80.f);
	circle.setPosition(col * 200.f + 20.f, row * 200.f + 20.f);	 // Midden van vak berekenen door 200/2 - 80/2 = 20
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineThickness(10.f);
	circle.setOutlineColor(sf::Color::Blue);
	window_.draw(circle);
}

void SFMLInterface::drawX(int row, int col) { 
	// Midden van het vakje berekenen
	float centerX = col * 200.f + 100.f;
	float centerY = row * 200.f + 100.f;
	for (float rotation : {45.f, -45.f}) { // stop de rotaties in een array zodat niet twee keer dezelfde code hoeven te schrijven
		sf::RectangleShape line(sf::Vector2f(160.f, 20.f));
		line.setOrigin(80.f, 10.f); // origin op midden van rechthoek zodat rotatie correct is
		line.setPosition(centerX, centerY); // gecentreerd in vakje
		line.setRotation(rotation);
		line.setFillColor(sf::Color::Red);
		window_.draw(line);
	}
}

void SFMLInterface::showWinner() {
	if (game_.isGameOver()) {
		if (game_.getWinner() == Player::X) {
			showMessage("Player X wins!");
		}
		else if (game_.getWinner() == Player::O) {
			showMessage("Player O wins!");
		}
		else {
			showMessage("The game is a draw!");
		}
		render(); // renderen zodat het bericht getoond wordt
	}
}

void SFMLInterface::showMessage(std::string message) {
	message_ = message; // Sla het bericht op in een member variable zodat het in de render functie getoond kan worden
	// kan niet van uit hier direct getoond worden omdat render() de enige functie is die toegang heeft tot het window_ object.
}

void SFMLInterface::waitForClose() {
	while (window_.isOpen()) {
		sf::Event event;
		while (window_.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {

				window_.close();
			}
		}
	}
}