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

std::vector<Position2D> Pawn::GetMoves(void) const noexcept
{
    std::vector<Position2D> moves;
    moves.reserve(2);

    // Pawn's movement direction depends on the colour of the piece
    if (colour_ == PieceColour::WHITE) {
        Position2D new_position = position_ + Position2D(Position2D::Direction2D::UP);
        // The pawn can move forward one square, but not out of bounds.
        if (!new_position.IsOutOfBounds(8, 8)) {
            moves.push_back(new_position);
        }

        // Prepare a second double move...
        new_position += Position2D(Position2D::Direction2D::UP);
        // ... but only if it's the first move of the pawn
        // Realistically it's not necessary to check out of bounds. The pawn can't be on the first
        // rank.
        if (!has_moved_) {
            moves.push_back(new_position);
        }
    }
    else {
        Position2D new_position = position_ + Position2D(Position2D::Direction2D::DOWN);
        // The pawn can move forward one square, but not out of bounds.
        if (!new_position.IsOutOfBounds(8, 8)) {
            moves.push_back(new_position);
        }

        // Prepare a second double move...
        new_position += Position2D(Position2D::Direction2D::DOWN);
        // ... but only if it's the first move of the pawn
        // Realistically it's not necessary to check out of bounds. The pawn can't be on the first
        // rank.
        if (!has_moved_) {
            moves.push_back(new_position);
        }
    }

    return moves;
}

void Pawn::Move(Position2D new_position) noexcept
{
    position_ = new_position;
    has_moved_ = true;
}

int Pawn::GetPointEvaulation(void) const noexcept
{
    return 1;
}

std::vector<Position2D> Pawn::GetAttackOnlyMoves(void) const noexcept
{
    std::vector<Position2D> moves;
    moves.reserve(2);

    if (colour_ == PieceColour::WHITE) {
        // The pawn can attack one square diagonally forward
        Position2D new_position = position_ + Position2D(Position2D::Direction2D::UP_RIGHT);
        if (!new_position.IsOutOfBounds(8, 8)) {
            moves.push_back(new_position);
        }

        new_position = position_ + Position2D(Position2D::Direction2D::UP_LEFT);
        if (!new_position.IsOutOfBounds(8, 8)) {
            moves.push_back(new_position);
        }
    }
    else if (colour_ == PieceColour::BLACK) {
        // The pawn can attack one square diagonally forward
        Position2D new_position = position_ + Position2D(Position2D::Direction2D::DOWN_RIGHT);
        if (!new_position.IsOutOfBounds(8, 8)) {
            moves.push_back(new_position);
        }

        new_position = position_ + Position2D(Position2D::Direction2D::DOWN_LEFT);
        if (!new_position.IsOutOfBounds(8, 8)) {
            moves.push_back(new_position);
        }
    }

    return moves;
}

bool Pawn::CanEnPassant(void) const noexcept { return true; }

bool Pawn::CanBePromoted(void) const noexcept
{
    if (colour_ == PieceColour::WHITE) {
        return position_.y == 7;
    }
    else if (colour_ == PieceColour::BLACK) {
        return position_.y == 0;
    }
}

bool Pawn::CanMoveTwoSquares(void) const noexcept { return !has_moved_; }
