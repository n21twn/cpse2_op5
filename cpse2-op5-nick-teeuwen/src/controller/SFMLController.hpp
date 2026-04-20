#pragma once
#include "headController.hpp"
#include "../model/game.hpp"
#include "../view/Interface.hpp"
#include <SFML/Graphics.hpp>

class SFMLController : public headController {
	public:
	SFMLController(Game& game, Interface& interface) : game_(game), interface_(interface) {}
	void handleInput() override;

private:
	Game& game_; // reference naar game, zodat we gegeven kunen uit lezen
	Interface& interface_;
};