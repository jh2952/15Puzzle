#ifndef POINT_H
#define POINT_H

#include "Direction.h"

#include <iostream>

class Point
{
private:
	int m_x{};
	int m_y{};
public:
	Point() = default;
	Point(int x, int y);

	int getX() { return m_x; }
	int getY() { return m_y; }

	friend bool operator==(Point p1, Point p2);
	friend bool operator!=(Point p1, Point p2);
	friend std::ostream& operator<<(std::ostream& out, Point& point);
	Point getAdjacentPoint(Direction dir);
};

#endif 