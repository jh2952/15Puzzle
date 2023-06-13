#include "Board.h"

#include <iostream>
#include <cassert>
#include <algorithm>

Board::Board() // Initalize the board in its solved state
{
	int number{ 1 };

	for (int row{ 0 }; row < g_Size; ++row)
	{
		for (int col{ 0 }; col < g_Size; ++col)
		{
			m_board[row][col] = number++;
		}
	}

	m_board[g_Size - 1][g_Size - 1] = 0;
}

std::ostream& operator<<(std::ostream& out, Board& board) // Output the board
{
	for (int i{ 0 }; i < g_consoleLines; ++i)
		std::cout << '\n';

	for (int row{ 0 }; row < g_Size; ++row)
	{
		for (int col{ 0 }; col < g_Size; ++col)
		{
			out << board.m_board[row][col];
		}
		out << '\n';
	}

	return out;
}

bool operator==(Board& board1, Board& board2) // Check if two boards are equal
{
	int count{};
	int total{ 16 };

	for (int row{}; row < g_Size; ++row)
	{
		for (int col{}; col < g_Size; ++col)
		{
			if (board1.m_board[row][col] == board2.m_board[row][col])
				++count; // If each tiles are equal, increment the count.
		}
	}

	return count == total; // If all tiles are equal, count will equal the total amount of array elements.
}

Point Board::findZero() // Output the coordinates of zero on the board
{
	//m_board[row][col]
	for (int y{}; y < g_Size; ++y)
	{
		for (int x{}; x < g_Size; ++x)
		{
			if (m_board[y][x].isEmpty())
				return Point{ x, y };
		}
	}

	assert(0 && "Zero not found");
	return Point{ 0, 0 };
}

bool Board::checkValid(Point zero, Direction dir) // Check if a move is restricted by the boundaries
{
	int x = zero.getAdjacentPoint(dir.getDir()).getX();
	int y = zero.getAdjacentPoint(dir.getDir()).getY();
	if ((x < 0 || x > g_Size - 1) || (y < 0 || y > g_Size - 1))
		return false;
	return true;
}

bool Board::moveTile(Point zero, Direction dir) // Move the empty tile
{
	if (checkValid(zero, dir))
	{
		switch (dir.getDir())
		{
		case Direction::up:
		{
			std::swap(m_board[zero.getY()][zero.getX()], m_board[zero.getY() - 1][zero.getX()]);
			return true;
		}
		case Direction::down:
		{
			std::swap(m_board[zero.getY()][zero.getX()], m_board[zero.getY() + 1][zero.getX()]);
			return true;
		}
		case Direction::left:
		{
			std::swap(m_board[zero.getY()][zero.getX()], m_board[zero.getY()][zero.getX() - 1]);
			return true;
		}
		case Direction::right:
		{
			std::swap(m_board[zero.getY()][zero.getX()], m_board[zero.getY()][zero.getX() + 1]);
			return true;
		}
		}
	}
	std::cout << "Invalid move\n";
	return false;
}

void Board::randomise() // Randomise the board state
{
	Point zero{ findZero() };
	int N = 1000; // Randomise using 1000 moves.
	
	for (int index{ 0 }; index < N; ++index)
	{
		moveTile(zero, Direction::randDir());
		zero = findZero();
	}
}

bool Board::playerWon() // Check the winstate
{
	Board winState{};
	return *this == winState;
}