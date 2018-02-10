#pragma once
#include "constexpr_string.h"
#include "board.h"
#include "player.h"
#include "game_state.h"

template<size_t Rows, size_t Cols>
class GameEngine {
public:
	constexpr GameEngine(const GameState& info)
		: _board{}
		, _player("erik", info.playerx, info.playery)
	{
		Update();
	}

	constexpr void Update() {
		_player.Update();
		_board.SetTile(_player.Icon(), _player.X(), _player.Y());
	}

	void Draw() const {
		_board.Draw();
	}

private:
	Board<Rows, Cols> _board;
	Player _player;
};
