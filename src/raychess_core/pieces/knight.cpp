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

std::vector<Position2D> Knight::GetMoves(void) noexcept
{
    std::vector<Position2D> moves;
    moves.reserve(8);
    moves.push_back(position_ + Position2D(1, 2));
    moves.push_back(position_ + Position2D(1, -2));
    moves.push_back(position_ + Position2D(-1, 2));
    moves.push_back(position_ + Position2D(-1, -2));
    moves.push_back(position_ + Position2D(2, 1));
    moves.push_back(position_ + Position2D(2, -1));
    moves.push_back(position_ + Position2D(-2, 1));
    moves.push_back(position_ + Position2D(-2, -1));
    return moves;
}
