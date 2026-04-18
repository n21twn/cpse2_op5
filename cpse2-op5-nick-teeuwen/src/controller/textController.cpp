
#include "textController.hpp"
#include <iostream>

void textController::handleInput() {
	int row ;
	int	col ;
	if (game_.currentPlayer() == Player::X) {
		interface_.showMessage("Player X's turn.");
	}
	else {
		interface_.showMessage("Player O's turn.");
	}

	interface_.showMessage("Enter your row:");
	std::cin >> row;
	interface_.showMessage("Enter your column:");
	std::cin >> col;

	while(!game_.makeMove(row, col)){
		interface_.showMessage("Invalid move, try again.");
		interface_.showMessage("Enter your row:");
		std::cin >> row;
		interface_.showMessage("Enter your column:");
		std::cin >> col;
	}
}