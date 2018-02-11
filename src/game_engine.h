#pragma once
#include <iostream>
#include <fstream>
#include "constexpr_string.h"
#include "board.h"
#include "player.h"
#include "game_state.h"

template<size_t Rows, size_t Cols>
class GameEngine {
public:
	constexpr GameEngine(const GameState& info, conststr input)
		: _board{}
		, _player("erik", info.playerx, info.playery)
		, _info(info)
	{
		Update(input);
	}

	constexpr void Update(const conststr& input) {
		_player.Update(input);
		_board.SetTile(_player.Icon(), _player.Y(), _player.X());
	}

	void Draw() const {
		_board.Draw();

		// Write meta file
		std::ofstream meta("meta.txt");
		meta << "R\"(\n";
		meta << _info.rows << " " << _info.cols << "\n";
		meta << _player.X() << " " << _player.Y() << "\n";

		meta << ")\"";
	}

private:
	Board<Rows, Cols> _board;
	Player _player;
	GameState _info;
};
