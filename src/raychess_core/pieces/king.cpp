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
    moves.push_back(position_ + Position2D(Position2D::Direction2D::UP));
    moves.push_back(position_ + Position2D(Position2D::Direction2D::DOWN));
    moves.push_back(position_ + Position2D(Position2D::Direction2D::LEFT));
    moves.push_back(position_ + Position2D(Position2D::Direction2D::RIGHT));
    moves.push_back(position_ + Position2D(Position2D::Direction2D::UP_LEFT));
    moves.push_back(position_ + Position2D(Position2D::Direction2D::UP_RIGHT));
    moves.push_back(position_ + Position2D(Position2D::Direction2D::DOWN_LEFT));
    moves.push_back(position_ + Position2D(Position2D::Direction2D::DOWN_RIGHT));
    return moves;
}
