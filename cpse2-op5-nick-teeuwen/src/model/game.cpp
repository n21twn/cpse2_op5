#pragma once
#include "game.hpp"

Game::Game() {
	// Constructor, hier hoef je niks te doen
}

bool Game::makeMove(int row, int col) {
	if (isGameOver()) {
	return false;
	}

	if (getCell(row, col) != Player::None) {
		return false;
	}

	Move move;
	move.row = row;
	move.col = col;
	move.player = currentPlayer();

	moves_.push_back(move); // add move to the vector of moves_
	return true;
}

void Game::undoMove() {
	if (!moves_.empty()) {
		moves_.pop_back(); // verwijder laatste element uit de vector, dit is de laatste gemaakte move
	}
}

bool Game:: isGameOver() const {
	if (checkWin(Player::X) || checkWin(Player::O)) {
		return true;
	}
	return moves_.size() == 9; // zijn maar 9 vakjes en als geen winnaar is dan is het remisse
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

// Checkt wie er aan zet is 
Player Game::currentPlayer() const {
	if (moves_.size() % 2 == 0) { // gebruik % modulo voor simple even oneven te berekenen.
		return Player::X;
	}
	else {
		return Player::O;
	}
}

// Checkt doormiddle van row en col welke speler er in die cel zit, als er geen move is gemaakt in die cel geeft het Player::None terug
Player Game::getCell(int row, int col) const {
	for (const Move& move : moves_) {
		if (move.row == row && move.col == col) {
			return move.player;
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