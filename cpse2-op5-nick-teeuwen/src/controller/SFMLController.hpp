#pragma once
#include "headController.hpp"
#include "../model/game.hpp"
#include "../view/Interface.hpp"


class SFMLController : public headController {
	public:
	SFMLController(Game& game, Interface& interface) : game_(game), interface_(interface) {}
	void handleInput() override;

private:
	Game& game_; 
	Interface& interface_;
};