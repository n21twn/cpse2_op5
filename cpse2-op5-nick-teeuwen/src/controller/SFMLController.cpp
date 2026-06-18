#include <iostream>
#include "SFMLController.hpp"
#include "../model/commands.hpp"

void SFMLController::handleInput() {
    int row, col;
    if (game_.currentPlayer() == Player::X) {
        interface_.showMessage("Player X's turn. Press U to undo and R to Restart.");
    }
    else {
        interface_.showMessage("Player O's turn. Press U to undo and R to Restart.");
    }

    interface_.render(); // renderen voordat we input vragen zodat spelers kunnen zien wat er op het bord staat voordat ze een zet doen
    // oneindige loop totdat een geldige zet is gemaakt of de speler kiest om terug te gaan
    while (true) {
        InputResult result = interface_.getPlayerInput(row, col);

        if (result == InputResult::Undo) {
            game_.undo();
            break;
        }
        if (result == InputResult::Restart) {
            game_.restart();
            break;
        }
        if (result == InputResult::Invalid) {
            interface_.showMessage("Invalid move, try again.");
            continue;
        }

        // result == InputResult::Move
        auto command = std::make_unique<MoveCommand>(row, col, game_.currentPlayer());
        if (game_.executeCommand(std::move(command))) { break; } // command uitvoeren; bij succes loop verlaten

        interface_.showMessage("Square occupied, try again.");
        interface_.render();
    }
}