/**
 * @file    queen.cpp
 *
 * @brief   Class representing a queen.
 *
 * @section DESCRIPTION
 *
 * Class representing a queen chess piece with its own unique behaviour.
 */

#include "queen.hpp"

using namespace raychess;

std::vector<Position2D> Queen::GetMoves(void) const noexcept
{
    std::vector<Position2D> moves;
    moves.reserve(28);

    Position2D new_position;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
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

int Queen::GetPointEvaulation(void) const noexcept
{
    return 9;
}
