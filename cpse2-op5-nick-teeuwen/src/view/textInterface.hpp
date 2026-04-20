#pragma once
#include "Interface.hpp"
#include "../model/game.hpp"

class textInterface : public Interface {
public:
	textInterface(Game& game) : game_(game) {}

	void render() override;
	void showWinner() override;
	void showMessage(std::string message) override;
	void waitForClose() override {} // niks laten doen omdat geen window creert
	virtual InputResult getPlayerInput(int& row, int& col) override;

private:
	Game& game_; // reference naar game, zodat we gegeven kunen uit lezen 
};