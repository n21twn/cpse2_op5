#pragma once
#include "Interface.hpp"
#include "../model/game.hpp"

class textInterface : public Interface {
public:
	textInterface(Game& game) : game_(game) {}

	void render() override;
	void showWinner() override;
	void showMessage(std::string message) override;

private:
	Game& game_; // reference naar game, zodat we gegeven kunen uit lezen 
};