#pragma once 
#include <vector>
#include "move.hpp"

class Game {
public:
	Game();

	bool makeMove(int row, int col);
	void undoMove();

	Player currentPlayer() const;
	Player getCell(int row, int col) const;
	bool isGameOver() const;
	Player getWinner() const;

private:
	std::vector<Move> moves_; // gebruik _ om aan te geven dat het een private member variable is

	bool checkWin(Player p) const;

};