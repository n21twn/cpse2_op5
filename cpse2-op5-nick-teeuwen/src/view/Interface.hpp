#pragma once
#include "../model/game.hpp"
#include <string>

class Interface {
public:
	virtual void render() = 0;
	virtual void showWinner() = 0;
	virtual void showMessage(std::string message) = 0;
	virtual ~Interface() = default;
};