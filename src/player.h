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

	constexpr void Update(conststr input) {
		if (input.equals("south") || input.equals("s") ) {
			++_y;
		}
		else if (input.equals("north") || input.equals("n")) {
			--_y;
		}
		else if (input.equals("west") || input.equals("w")) {
			--_x;
		}
		else if (input.equals("east") || input.equals("e")) {
			++_x;
		}
	}

	constexpr char Icon() const { return _icon; }
	constexpr int X() const { return _x; }
	constexpr int Y() const { return _y; }
private:
	char _icon;
	conststr _name;
	int _x;
	int _y;

};
