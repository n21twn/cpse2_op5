#pragma once
#include "command.hpp"
#include "game.hpp"

class MoveCommand : public Command {
public:
    MoveCommand(Game& game, int row, int col)
        : game_(game), row_(row), col_(col), player_(game.currentPlayer()) {
    }

    bool execute() override {
        if (row_ < 0 || row_ > 2 || col_ < 0 || col_ > 2) { return false; }
        if (game_.getCell(row_, col_) != Player::None) { return false; }
        return true; // geldige zet: Game::executeCommand() voegt dit command toe aan de geschiedenis
    }

    Player playerAt(int row, int col) const override {
        if (row == row_ && col == col_) { return player_; }
        return Player::None;
    }

private:
    Game& game_;
    int row_;
    int col_;
    Player player_; // vastgelegd bij aanmaak, zodat getCell() later niet currentPlayer() hoeft te raden
};