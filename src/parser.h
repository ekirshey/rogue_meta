#pragma once
#include <utility>
#include "game_state.h"
#include "constexpr_string.h"

constexpr int stoi(const conststr& s, int start, int& end) {
	int result = 0;

	int i = start;
	char val = s[i];
	while (val >= '0' && val <= '9') {
		result = result * 10 + (val - '0');
		val = s[++i];
	}

	end = i;
	return result;
}

/*
	Parse meta info
	Format:
	BoardRows BoardCols
	PlayerX PlayerY
*/
constexpr GameState GetGameState(conststr info) {
	GameState gamestate;
	int end = 0;
	int start = 1;
	gamestate.rows = stoi(info, start, end);
	start = ++end;	// Skip space
	gamestate.cols = stoi(info, start, end);
	start = ++end; 	// skip new line
	gamestate.playerx = stoi(info, start, end);
	start = ++end;	// skip space
	gamestate.playery = stoi(info, start, end);

	return gamestate;
}
