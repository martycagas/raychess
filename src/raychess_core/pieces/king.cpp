/**
 * @file    king.cpp
 *
 * @brief   Class representing a king.
 *
 * @section DESCRIPTION
 *
 * Class representing a king chess piece with its own unique behaviour.
 */

#include "king.hpp"

using namespace raychess;

std::vector<Position2D> King::GetMoves(void) noexcept
{
    std::vector<Position2D> moves;
    moves.reserve(8);

    Position2D new_position;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            new_position = position_ + Position2D(i, j);
            if (!new_position.IsOutOfBounds(8, 8)) {
                moves.push_back(new_position);
            }
        }
    }
    return moves;
}
