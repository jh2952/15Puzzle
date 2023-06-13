#include "Direction.h"
#include "Random.h"

#include <cassert>

Direction::Direction(Dir direction) : m_direction{ direction } {} // Constructor

Direction Direction::operator-(Direction& dir) // Return opposite direction
{
	switch (dir.m_direction)
	{
	case up:    return down;
	case down:  return up;
	case left:  return right;
	case right: return left;
	}

	assert(0 && "Invalid Argument");
	return Direction{ up };
}

std::ostream& operator<<(std::ostream& out, Direction dir) // Output the direction
{
	switch (dir.m_direction)
	{
	case Direction::up:    std::cout << "Up";    return out;
	case Direction::down:  std::cout << "Down";  return out;
	case Direction::left:  std::cout << "Left";  return out;
	case Direction::right: std::cout << "Right"; return out;
	default:			   std::cout << "N/A";   return out;
	}
}

Direction Direction::randDir() // Return a random cardinal direction
{
	return Direction{ Dir{static_cast<Dir>(Random::get(0,3))} };
}