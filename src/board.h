#pragma once
template<int Rows, int Cols>
class Board {
public:
	constexpr Board() 
		: _board{}
	{
		for (int i = 0; i < Rows; ++i) {
			for (int j = 0; j < Cols; ++j) {
				_board[i][j] = ' ';
				if (j == 0 || j == 9) {
					_board[i][j] = '|';
				}
				if (i == 0 || i == 9) {
					_board[i][j] = '_';
				}
			}
		}
	}

	constexpr void SetTile(const char val, int i, int j) {
		_board[i][j] = val;
	}

	void Draw() const {
		for (int i = 0; i < Rows; ++i) {
			for (int j = 0; j < Cols; ++j) {
				std::cout << _board[i][j];
			}
			std::cout << std::endl;
		}
	}

private:
	std::array<std::array<char, Rows>, Cols> _board;
};
