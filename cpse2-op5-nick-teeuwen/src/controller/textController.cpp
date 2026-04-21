
#include "textController.hpp"
#include <iostream>



// Deze functie handelt de input van de speler af. Het vraagt om de rij en kolom waar de speler een zet wil doen, en verwerkt deze input.
void textController::handleInput() {
	int row ;
	int	col ;
	if (game_.currentPlayer() == Player::X) {
		interface_.showMessage("Player X's turn.");
	}
	else {
		interface_.showMessage("Player O's turn.");
	}

	// loop voor het zetten van de move en het catchen van errors.
	while (true) {
		InputResult result = interface_.getPlayerInput(row, col);
		if (result == InputResult::Undo) {
			game_.undoMove();
			break;// als move gelukt is dan return, anders loop verder en vraag opnieuw om input
		}
		if(result == InputResult::Invalid) {
			interface_.showMessage("Invalid input, only numbers are allowed and 'u'.");
			continue; // loop opnieuw starten
		}
		if(game_.makeMove(row, col)) { break; }// als move gelukt is dan return, anders loop verder en vraag opnieuw om input
		interface_.showMessage("Invalid move, try again.");
	}

}