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

std::vector<Position2D> Rook::GetMoves(void) noexcept
{
    std::vector<Position2D> moves;
    moves.reserve(14);

    for (size_t i = 0; i < 4; i++) {
        // Itereate from 1 to 8 to save us adding that 1 to each case.
        for (size_t j = 1; j < 9; j++) {
            Position2D new_position = position_;
            switch (i) {
                case 0:
                    new_position += (Position2D(Position2D::Direction2D::UP) * j);
                    break;
                case 1:
                    new_position += (Position2D(Position2D::Direction2D::DOWN) * j);
                    break;
                case 2:
                    new_position += (Position2D(Position2D::Direction2D::LEFT) * j);
                    break;
                case 3:
                    new_position += (Position2D(Position2D::Direction2D::RIGHT) * j);
                    break;
            }
            if (new_position.IsOutOfBounds(8, 8)) {
                break; // If a result is out of bounds, we can stop the inner loop.
            }
            else {
                moves.push_back(new_position);
            }
        }
    }

    return moves;
}
