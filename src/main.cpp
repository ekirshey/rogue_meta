/****************************
*
* Compile time "simple" rogue like.
* This is a completely toy project and serves
* no real purpose beyond my own curiosity
*
* Author: ekirshey
* Created: Sat Feb 10 11:11:59 2018
****************************/

#include <iostream>
#include <string>
#include <array>
#include "constexpr_string.h"
#include "game_engine.h"
#include "game_state.h"
#include "parser.h"


int main(int argc, char* argv[]) {
	constexpr auto game_info = conststr(
#include "../meta.txt"
	);
	constexpr auto state = GetGameState(game_info);
	constexpr GameEngine<state.rows, state.cols> game_engine(state, KEYBOARD_INPUT);
	game_engine.Draw();

	return 0;
}
		