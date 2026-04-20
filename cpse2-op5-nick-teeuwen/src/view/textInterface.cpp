
#include "textInterface.hpp"
#include <iostream>
#include <stdexcept>

InputResult textInterface::getPlayerInput(int& row, int& col) {
	std::string input;
	showMessage("Enter your 'u' for undo or enter row:");
	std::cin >> input;
	if (input == "u") { return InputResult::Undo; }
	try {
		row = std::stoi(input); // zet string terug om naar Int
	}
	catch (std::invalid_argument&) { // Ai geholpen met functie vinden die invalid argument exception gooit.
		return InputResult::Invalid; // als er iets anders is ingevoerd dan een getal of 'u' dan is het ongeldig
	}
	showMessage("Enter your column:");
	std::cin >> col;
	return InputResult::Move;
}


// Print het bord in het console, Met strepen tussen de cellen.
void textInterface::render() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j){ 

			if (game_.getCell(i, j) == Player::X) {
				std::cout << "X ";
			}
			else if (game_.getCell(i, j) == Player::O) {
				std::cout << "O ";
			}else if(game_.getCell(i, j) == Player::None){
				std::cout << "_ ";
			}
			else {
				throw std::runtime_error("Invalid player value");
			}
			if (j < 2) { std::cout << "| "; }
		}
		std::cout << std::endl;
		if (i < 2) {std::cout << "---------\n";}
	}
	std::cout << std::endl;
}

void textInterface::showWinner() {
	if (game_.isGameOver()) {
		if (game_.getWinner() == Player::X) {
			std::cout << "Player X wins!" << std::endl;
		}
		else if (game_.getWinner() == Player::O) {
			std::cout << "Player O wins!" << std::endl;
		}
		else {
			std::cout << "The game is a draw!" << std::endl;
		}
	}
}

void textInterface::showMessage(std::string message) {
	std::cout << message << std::endl;
}
