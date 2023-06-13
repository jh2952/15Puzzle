#include "Tile.h"
#include "Board.h"
#include "UserInput.h"
#include "Direction.h"
#include "Point.h"

#include <iostream>

int main()
{
    // Initialize and randomise initial board - display it
    Board board{};
    board.randomise();
    std::cout << board;

    // Track player position on the board
    Point player{ board.findZero() };

    while (true)
    {
        char input{ UserInput::getInput() };

        // Quit condition
        if (input == 'q')
        {
            std::cout << "\nBye\n";
            break;
        }

        if (board.moveTile(player, UserInput::convertToDir(input))) // If the player move was valid...
        {
            player = board.findZero(); // ...reassign the player's position...
            std::cout << board;        // ...and output the board.
        }

        // Check winstate
        if (board.playerWon())
        {
            std::cout << "\n\nYou Won!\n\n";
            break;
        }
    }

    return 0;
}