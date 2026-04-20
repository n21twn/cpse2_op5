#include <iostream>
#include "SFMLController.hpp"


void SFMLController::handleInput() {
    int row, col;
    if (game_.currentPlayer() == Player::X) {
        interface_.showMessage("Player X's turn. Press U to undo.");
    }
    else {
        interface_.showMessage("Player O's turn. Press U to undo.");
    }

	interface_.render(); // renderen voordat we input vragen zodat spelers kunnen zien wat er op het bord staat voordat ze een zet doen

    while (true) {
        InputResult result = interface_.getPlayerInput(row, col);
        if (result == InputResult::Undo) {
            game_.undoMove();
            break;
        }
        if (result == InputResult::Invalid) {
            interface_.showMessage("Invalid move, try again.");
            continue;
        }
        if (game_.makeMove(row, col)) { break; }

        interface_.showMessage("Square occupied, try again.");
        interface_.render();
    }
}