#pragma once 
#include <vector>
#include <memory>          // ← voor unique_ptr
#include "move.hpp"
#include "moveCommand.hpp"


class Game {
public:
    Game();

    bool executeCommand(std::unique_ptr<MoveCommand> command);
    void undo();
    void restart();

    Player currentPlayer() const;
    Player getCell(int row, int col) const;
    bool isGameOver() const;
    Player getWinner() const;

private:
    std::vector<std::unique_ptr<MoveCommand>> commands_;

    bool checkWin(Player p) const;
};