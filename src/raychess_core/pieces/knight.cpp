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

std::vector<Position2D> Knight::GetMoves(const BoardArea& board) const noexcept
{
    std::vector<Position2D> moves;
    moves.reserve(8);

    Position2D new_position;

    /*
     * The way this algorithm works is iterating over all possible directions using the two for
     * loops (each i, j pair could be considered a directional vector) and then adding the
     * directional vector to the current position until the new position is out of bounds or there
     * is a piece in the way. In case this piece is an enemy piece, the move is added to the list of
     * possible moves as well.
     */
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (i == 0 || j == 0 || i == j) {
                continue;
            }
            new_position = position_ + Position2D(i, j);
            // The move can be added to the list if it's within bounds and if there is either no
            // piece or an enemy piece.
            if (board.IsWithinBounds(new_position)) {
                if (board.GetPieceAt(new_position) == nullptr ||
                    board.GetPieceAt(new_position)->GetColour() != colour_) {
                    moves.push_back(new_position);
                }
            }
        }
    }

    return moves;
}

int Knight::GetPointEvaulation(void) const noexcept { return 3; }
