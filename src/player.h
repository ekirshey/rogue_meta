#pragma once
#include "board.h"
#include "constexpr_string.h"


class Player {
public:
	constexpr Player(conststr name, int x, int y) 
		: _icon('o')
		, _name(name)
		, _x(x)
		, _y(y)
	{ }

	constexpr void Update() {
		_x++;
		_y++;
	}

	constexpr char Icon() { return _icon; }
	constexpr int X() { return _x; }
	constexpr int Y() { return _y; }
private:
	char _icon;
	conststr _name;
	int _x;
	int _y;

};
