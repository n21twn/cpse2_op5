#pragma once
#include "headController.hpp"
#include "../model/game.hpp"
#include "../view/Interface.hpp"

enum class InputResult { Move, Undo, Invalid}; 
// help van AI maak enum zodat checken van input makkelijker gaat en niet gedupliceerd wordt.
// invalid toegevoegd om stio exception te kunne op vangen.

class textController : public headController {
public:
	textController(Game& game, Interface& interface) : game_(game), interface_(interface) {}

	void handleInput() override;

private:
		Game& game_; // reference naar game, zodat we gegeven kunen uit lezen
		Interface& interface_;
		InputResult getInput(int& row, int& col);
};