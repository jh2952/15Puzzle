#ifndef DIRECTION_H
#define DIRECTION_H

#include <iostream>

class Direction
{
public:
	enum Dir
	{
		up,
		down,
		left,
		right,
		max_directions,
	};

	Dir getDir() { return m_direction; }

	Direction() = default;
	Direction(Dir direction);
	Direction operator-(Direction& dir);
	friend std::ostream& operator<<(std::ostream& out, Direction dir);
	static Direction randDir();

private:
	Dir m_direction{};
};

#endif