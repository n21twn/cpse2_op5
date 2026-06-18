#include "game.hpp"


Game::Game() {
	// Constructor, hier hoef je niks te doen
}

bool Game::executeCommand(std::unique_ptr<MoveCommand> command) {
    if (isGameOver()) return false;
    if (command->getRow() < 0 || command->getRow() > 2) return false;
    if (command->getCol() < 0 || command->getCol() > 2) return false;
    if (getCell(command->getRow(), command->getCol()) != Player::None) return false;

    command->execute();
    commands_.push_back(std::move(command)); // opslaan in de vector
    return true;
}

void Game::undo() {
    if (!commands_.empty()) {
        commands_.back()->undo();
        commands_.pop_back();
    }
}

Player Game::currentPlayer() const {
    if (commands_.size() % 2 == 0) return Player::X;
    else return Player::O;
}

Player Game::getCell(int row, int col) const {
    for (const auto& command : commands_) {
        if (command->getRow() == row && command->getCol() == col) {
            return command->getPlayer();
        }
    }
    return Player::None;
}

Player Game::getWinner() const {
	if (checkWin(Player::X)) {
		return Player::X;
	}
	if (checkWin(Player::O)) {
		return Player::O;
	}
	return Player::None; // als er geen winnaar is, return None

}

void Game::restart() {
    commands_.clear();
}

bool Game::isGameOver() const {
	if (checkWin(Player::X) || checkWin(Player::O)) {
		return true;
	}
	return commands_.size() == 9; // zijn maar 9 vakjes en als geen winnaar is dan is het remisse
}

bool Game::checkWin(Player p) const {
	for (int i = 0; i < 3; ++i) {
		if (getCell(i, 0) == p && getCell(i, 1) == p && getCell(i, 2) == p) { return true; }// Checkt of er 3 op een rij is op de horizontale lijnen
		if (getCell(0, i) == p && getCell(1, i) == p && getCell(2, i) == p) { return true; }// Checkt of er 3 op een rij is op de verticale lijnen
	}

	if (getCell(0, 0) == p && getCell(1, 1) == p && getCell(2, 2) == p) { return true; } // Checkt of er 3 op een rij is op de diagonaal van linksboven naar rechtsonder
	if (getCell(0, 2) == p && getCell(1, 1) == p && getCell(2, 0) == p) { return true; } // Checkt of er 3 op een rij is op de diagonaal van rechtsboven naar linksonder

	return false;
}