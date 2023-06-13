#include <iostream>
#include "Tile.h"

// Tile Constructor
Tile::Tile(int number) : m_number{ number } {}

bool Tile::isEmpty() { return m_number == 0; }

// Ensure correct spacing on the grid when outputting tiles.
std::ostream& operator<<(std::ostream& out, Tile& tile)
{
	if (tile.m_number > 9) // if two digit number
	{
		out << " " << tile.m_number << " ";
	}
	else if (tile.m_number > 0) // if one digit number
	{
		out << "  " << tile.m_number << " ";
	}
	else if (tile.m_number == 0)
	{
		out << "    ";
	}
	return out;
}

bool operator==(Tile& tile1, Tile& tile2)
{
	return tile1.m_number == tile2.m_number;
}