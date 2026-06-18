#pragma once

class Command {
public:
    virtual bool execute() = 0; // bool: true als de actie geslaagd is
    virtual ~Command() = default;
};