/**
 * @file    knight.cpp
 *
 * @brief   Class representing a knight.
 *
 * @section DESCRIPTION
 *
 * Class representing a knight chess piece with its own unique behaviour.
 */

#include "knight.hpp"

using namespace raychess;

std::vector<Position2D> Knight::GetMoves(void) const noexcept
{
    std::vector<Position2D> moves;
    moves.reserve(8);

    Position2D new_position;

    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (i == 0 || j == 0 || i == j) {
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

int Knight::GetPointEvaulation(void) const noexcept
{
    return 3;
}
