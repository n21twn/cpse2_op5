#pragma once 
#include <vector>
#include <memory>
#include "move.hpp"
#include "command.hpp"

class Game {
public:
    Game();

    bool executeCommand(std::unique_ptr<Command> command);
    void undo();
    void restart();

    Player currentPlayer() const;
    Player getCell(int row, int col) const;
    bool isGameOver() const;
    Player getWinner() const;

private:
    //stl container gebruiken om de geschiedenis van uitgevoerde commands bij te houden
    std::vector<std::unique_ptr<Command>> history_;

    bool checkWin(Player p) const;
};