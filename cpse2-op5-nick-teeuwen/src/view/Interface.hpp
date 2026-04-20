#pragma once
#include "../model/game.hpp"
#include "../model/inputResult.hpp"
#include <string>

class Interface {
public:
	virtual void render() = 0;
	virtual void showWinner() = 0;
	virtual void showMessage(std::string message) = 0;
	virtual void waitForClose() = 0;
	virtual InputResult getPlayerInput(int& row, int& col) = 0;
	virtual ~Interface() = default;
};