/**
 * @file    rook.cpp
 *
 * @brief   Class representing a rook.
 *
 * @section DESCRIPTION
 *
 * Class representing a rook chess piece with its own unique behaviour.
 */

#include "rook.hpp"

using namespace raychess;

std::vector<Position2D> Rook::GetMoves(void) const noexcept
{
    std::vector<Position2D> moves;
    moves.reserve(14);

    Position2D new_position;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            // Aternatively, the following condition could be written as:
            // if (abs(i) == abs(j))
            // Yes, this is a flex, but I'm not putting it in the actual code.
            if ((i != 0 && j != 0) || (i == 0 && j == 0)) {
                continue;
            }
            new_position = position_ + Position2D(i, j);
            while (!new_position.IsOutOfBounds(8, 8)) {
                moves.push_back(new_position);
                new_position += Position2D(i, j);
            }
        }
    }

    return moves;
}
