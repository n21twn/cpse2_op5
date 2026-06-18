#pragma once

class Command {
public:
    virtual bool execute() = 0; // bool: true als de actie geslaagd is
    virtual void undo() = 0;
    virtual ~Command() = default;
};