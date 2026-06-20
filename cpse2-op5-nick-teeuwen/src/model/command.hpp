#pragma once
#include   "move.hpp"

class Command {
public:
    virtual bool execute() = 0; // bool: true als de actie geslaagd is
    virtual Player playerAt(int row, int col) const { return Player::None; }
    virtual ~Command() = default;
};