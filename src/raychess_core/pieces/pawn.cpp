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

std::vector<Position2D> Pawn::GetMoves(const BoardArea& board) const noexcept
{
    std::vector<Position2D> moves;
    moves.reserve(2);

    // Check whether we should move once or twice
    int available_moves = (has_moved_ ? 1 : 2);

    // Perform the same code 1 to 2 times
    for (int i = 1; i <= available_moves; i++) {
        Position2D new_position = position_;

        // Determine the direction based on the piece's colour
        if (colour_ == PieceColour::WHITE) {
            new_position.y += i;
        }
        else {
            new_position.y -= i;
        }

        // The move can only be performed when it is within bounds and there isn't a piece (any
        // piece) at the given position. Given the moves are resolved sequentially in a direct,
        // pieces "in the way" block all other subsequent moves.
        if (!new_position.IsOutOfBounds(board.GetDimensionX(), board.GetDimensionY()) &&
            board.GetPieceAt(new_position) == nullptr) {
            moves.push_back(new_position);
        }
        else {
            break;
        }
    }

    return moves;
}

void Pawn::Move(Position2D new_position) noexcept
{
    position_ = new_position;
    has_moved_ = true;
}

int Pawn::GetPointEvaulation(void) const noexcept { return 1; }

std::vector<Position2D> Pawn::GetAttackOnlyMoves(const BoardArea& board) const noexcept
{
    std::vector<Position2D> moves;
    moves.reserve(2);

    // Iterate over left and right directions (the X axis)
    for (int i = -1; i <= 1; i += 2) {
        Position2D new_position = position_;

        // Pawn's vertical direction depends on the colour of the piece, but it's always one tile
        // "forward"
        if (colour_ == PieceColour::WHITE) {
            new_position += Position2D(i, 1);
        }
        else {
            new_position += Position2D(i, -1);
        }

        // If the tile is within bounds and there is an enemy piece there add it to the list.
        if (!new_position.IsOutOfBounds(board.GetDimensionX(), board.GetDimensionY()) &&
            board.GetPieceAt(new_position) != nullptr) {
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
