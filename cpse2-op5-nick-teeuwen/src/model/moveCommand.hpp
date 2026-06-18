#pragma once
#include "command.hpp"
#include "move.hpp"  

class MoveCommand : public Command {
public:
    MoveCommand(int row, int col, Player player): row_(row), col_(col), player_(player) {}

    bool execute() override { return true; } // het 'uitvoeren' is het opslaan door Game zelf
    void undo() override {}                  // het 'ongedaan maken' is het verwijderen door Game zelf

    int getRow() const { return row_; }
    int getCol() const { return col_; }
    Player getPlayer() const { return player_; }

private:
    int row_;
    int col_;
    Player player_;
};