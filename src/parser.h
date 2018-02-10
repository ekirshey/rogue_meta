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

 constexpr GameState GetGameState(conststr info) {
	GameState gamestate;
	int end = 0;
	gamestate.rows = stoi(info, 1, end);
	int colstart = ++end;
	gamestate.cols = stoi(info, colstart, end);

	return gamestate;
}
