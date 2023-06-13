#include "Point.h"

#include <cassert>

Point::Point(int x, int y) : m_x{ x }, m_y{ y } {} // Constructor

bool operator==(Point p1, Point p2)
{
	return (p1.m_x == p2.m_x && p1.m_y == p2.m_y);
}

bool operator!=(Point p1, Point p2)
{
	return !(p1 == p2);
}

std::ostream& operator<<(std::ostream& out, Point& point)
{
	out << '(' << point.m_x << ", " << point.m_y << ')';
	return out;
}

Point Point::getAdjacentPoint(Direction dir) // Return the point adjacent in the direction provided as an argument.
{
	switch (dir.getDir())
	{
	case Direction::up:    return Point{ m_x, m_y - 1 };
	case Direction::down:  return Point{ m_x, m_y + 1 };
	case Direction::left:  return Point{ m_x - 1, m_y };
	case Direction::right: return Point{ m_x + 1, m_y };
	}

	assert(0 && "Invalid Argument");
	return Point{ 0, 0 };
}