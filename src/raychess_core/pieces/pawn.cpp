/**
 * @file    pawn.cpp
 *
 * @brief   Class representing a pawn.
 *
 * @section DESCRIPTION
 *
 * Class representing a pawn chess piece with its own unique behaviour.
 */

#include "pawn.hpp"

using namespace raychess;

std::vector<Position2D> Pawn::GetMoves(void) noexcept
{
    std::vector<Position2D> moves;
    moves.reserve(2);

    // The pawn can move forward one square
    moves.push_back(position_ + Position2D::Direction2D::UP);

    // If it hasn't moved yet, also add movement two squares ahead
    if (!has_moved_) {
        moves.push_back(position_ + Position2D::Direction2D::UP + Position2D::Direction2D::UP);
    }

    return moves;
}

std::vector<Position2D> Pawn::GetAttackOnlyMoves(void) noexcept
{
    std::vector<Position2D> moves;
    moves.reserve(2);

    // The pawn can attack one square diagonally forward
    moves.push_back(position_ + Position2D::Direction2D::UP_LEFT);
    moves.push_back(position_ + Position2D::Direction2D::UP_RIGHT);

    return moves;
}

void Pawn::Move(Position2D new_position) noexcept
{
    position_ = new_position;
    has_moved_ = true;
}
