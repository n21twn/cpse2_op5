#pragma once
#include "command.hpp"
#include "game.hpp"

class UndoCommand : public Command {
public:
    UndoCommand(Game& game) : game_(game) {}

    bool execute() override {
        game_.undoMove();
        return true; // undo faalt nooit expliciet
    }

private:
    Game& game_;
};