#pragma once
#include "command.hpp"
#include "game.hpp"

class MoveCommand : public Command {
public:
    MoveCommand(Game& game, int row, int col) : game_(game), row_(row), col_(col) {}

    bool execute() override {
        return game_.makeMove(row_, col_); // Game is de Receiver
    }

private:
    Game& game_;
    int row_;
    int col_;
};