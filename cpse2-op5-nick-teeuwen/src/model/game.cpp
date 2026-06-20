#include "game.hpp"

Game::Game() {
	// Constructor, hier hoef je niks te doen
}

bool Game::executeCommand(std::unique_ptr<Command> command) {
	if (isGameOver()) { return false; }
	if (!command->execute()) { return false; } // command checkt zelf of de zet geldig is
	history_.push_back(std::move(command)); // alleen geslaagde commands komen in de geschiedenis
	return true;
}

void Game::undo() {
	if (!history_.empty()) {
		history_.pop_back(); // het laatste commando 'negeren' = undo
	}
}

void Game::restart() {
	history_.clear(); // directe actie, geen command-object nodig (zie toelichting hieronder)
}

// Checkt wie er aan zet is
Player Game::currentPlayer() const {
	if (history_.size() % 2 == 0) {
		return Player::X;
	}
	else {
		return Player::O;
	}
}

// Doorloopt de geschiedenis van commands (van laatst naar eerst) en vraagt
// elk command of het deze cel bezet. Zo wordt het bord nergens los opgeslagen.
Player Game::getCell(int row, int col) const {
	for (auto it = history_.rbegin(); it != history_.rend(); ++it) {
		Player p = (*it)->playerAt(row, col);
		if (p != Player::None) { return p; }
	}
	return Player::None;
}

bool Game::checkWin(Player p) const {
	for (int i = 0; i < 3; ++i) {
		if (getCell(i, 0) == p && getCell(i, 1) == p && getCell(i, 2) == p) { return true; }
		if (getCell(0, i) == p && getCell(1, i) == p && getCell(2, i) == p) { return true; }
	}
	if (getCell(0, 0) == p && getCell(1, 1) == p && getCell(2, 2) == p) { return true; }
	if (getCell(0, 2) == p && getCell(1, 1) == p && getCell(2, 0) == p) { return true; }
	return false;
}

bool Game::isGameOver() const {
	if (checkWin(Player::X) || checkWin(Player::O)) {
		return true;
	}
	return history_.size() == 9;
}

Player Game::getWinner() const {
	if (checkWin(Player::X)) {
		return Player::X;
	}
	if (checkWin(Player::O)) {
		return Player::O;
	}
	return Player::None;
}