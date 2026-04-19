
#include "textController.hpp"
#include <iostream>


InputResult textController::getInput(int& row, int& col) {
	std::string input;
	interface_.showMessage("Enter your 'u' for undo or enter row:");
	std::cin >> input;
	if (input == "u") { return InputResult::Undo; }
	try{
		row = std::stoi(input); // zet string terug om naar Int
	}
	catch(std::invalid_argument&){ // Ai geholpen met functie vinden die invalid argument exception gooit.
		return InputResult::Invalid; // als er iets anders is ingevoerd dan een getal of 'u' dan is het ongeldig
	}
	interface_.showMessage("Enter your column:");
	std::cin >> col;
	return InputResult::Move;
}
void textController::handleInput() {
	int row ;
	int	col ;
	if (game_.currentPlayer() == Player::X) {
		interface_.showMessage("Player X's turn.");
	}
	else {
		interface_.showMessage("Player O's turn.");
	}


	while (true) {
		InputResult result = getInput(row, col);
		if (result == InputResult::Undo) {
			game_.undoMove();
			break;// als move gelukt is dan return, anders loop verder en vraag opnieuw om input
		}
		if(result == InputResult::Invalid) {
			interface_.showMessage("Invalid input, only numbers are allowed and 'u'.");
		}
		if(game_.makeMove(row, col)) { break; }// als move gelukt is dan return, anders loop verder en vraag opnieuw om input
		interface_.showMessage("Invalid move, try again.");
	}

}