#pragma once
#include "command.hpp"
#include "game.hpp"

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