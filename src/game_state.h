#pragma once
#include "constexpr_string.h"

struct GameState {
	constexpr GameState() 
		: rows(0)
		, cols(0)
		, playerx(1)
		, playery(1)
	{ }

	int rows;
	int cols;
	int playerx;
	int playery;
};
