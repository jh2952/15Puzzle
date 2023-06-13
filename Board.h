#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include "Point.h"
#include "Direction.h"

#include <array>

constexpr int g_Size{ 4 };
constexpr int g_consoleLines{ 25 };

class Board
{
public:
	Board(); // Constructor

	friend std::ostream& operator<<(std::ostream& out, Board& board);
	friend bool operator==(Board& board1, Board& board2);


	Point findZero();
	void randomise();
	bool checkValid(Point zero, Direction dir);
	bool moveTile(Point point, Direction dir);
	bool playerWon();
private:
	Tile m_board[g_Size][g_Size]{}; // 2D 4X4 Array
};

#endif