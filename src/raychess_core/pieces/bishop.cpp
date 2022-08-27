/**
 * @file    bishop.cpp
 *
 * @brief   Class representing a bishop.
 *
 * @section DESCRIPTION
 *
 * Class representing a bishop chess piece with its own unique behaviour.
 */

#include "bishop.hpp"

using namespace raychess;

std::vector<Position2D> Bishop::GetMoves(void) const noexcept
{
    std::vector<Position2D> moves;
    moves.reserve(14);

    Position2D new_position;

    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            // No need for a check here, the loop condition ensures that i and j are both either -1,
            // or 1.
            new_position = position_ + Position2D(i, j);
            while (!new_position.IsOutOfBounds(8, 8)) {
                moves.push_back(new_position);
                new_position += Position2D(i, j);
            }
        }
    }

    return moves;
}
