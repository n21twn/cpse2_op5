#pragma once
#include "../model/inputResult.hpp"

class headController {
public:

	virtual void handleInput() = 0;
	virtual ~headController() = default;

};