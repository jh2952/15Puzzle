#ifndef TILE_H
#define TILE_H

#include <iostream>

class Tile
{
private:
	int m_number{};
public:
	Tile() = default;
	Tile(int number);
	bool isEmpty();

	friend std::ostream& operator<<(std::ostream& out, Tile& tile);
	friend bool operator==(Tile& tile1, Tile& tile2);

	// Getter
	int getNum() { return m_number; }
};

#endif 