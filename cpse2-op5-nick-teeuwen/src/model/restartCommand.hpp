#pragma once
#include "command.hpp"
#include "game.hpp"

// LET OP: deze class wordt momenteel niet gebruikt in de controllers.
// Restart wordt rechtstreeks via game_.restart() aangeroepen, omdat een
// restart de hele command-geschiedenis wist en dus geen zin heeft om
// zelf in die geschiedenis opgeslagen te worden.

class RestartCommand : public Command {
public:
    RestartCommand(Game& game) : game_(game) {}

    bool execute() override {
        game_.restart();
        return true;
    }

private:
    Game& game_;
};