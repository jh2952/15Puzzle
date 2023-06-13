#ifndef USERINPUT_H
#define USERINPUT_H

#include "Direction.h"

#include <iostream>
#include <limits>
#include <cassert>

namespace UserInput
{
	bool valid(char c)
	{
		return c == 'w' ||
			   c == 'a' ||
			   c == 's' ||
			   c == 'd' ||
			   c == 'q';
	}

	char getChar()
	{
		char c{};
		std::cin >> c;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return c;
	}

	char getInput()
	{
		std::cout << "Enter a command: ";
		char c{};
		while (!valid(c))
		{
			c = getChar();
		}
		return c;
	}

	Direction convertToDir(char c)
	{
		switch (c)
		{
		case 'w': return Direction{ Direction::up };
		case 'a': return Direction{ Direction::left };
		case 's': return Direction{ Direction::down };
		case 'd': return Direction{ Direction::right };
		}

		assert(0 && "Invalid Argument");
		return Direction{ Direction::up };
	}
}

#endif