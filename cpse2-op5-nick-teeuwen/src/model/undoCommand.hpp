#pragma once
#include "command.hpp"
#include "game.hpp"

// LET OP: deze class wordt momenteel niet gebruikt in de controllers.
// Undo wordt rechtstreeks via game_.undo() aangeroepen, omdat undo geen
// onderdeel is van de opgeslagen command-geschiedenis (zie game.hpp:
// vector<unique_ptr<MoveCommand>> commands_).

class UndoCommand : public Command {
public:
    UndoCommand(Game& game) : game_(game) {}

    bool execute() override {
        game_.undo();
        return true; // undo faalt nooit expliciet
    }

private:
    Game& game_;
};