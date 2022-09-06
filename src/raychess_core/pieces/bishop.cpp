/**
 * @file    bishop.cpp
 *
 * @brief   Class representing a bishop.
 *
 * @section DESCRIPTION
 *
 * Class representing a bishop chess piece with its own unique behaviour.
 */

#include "bishop.hpp"

using namespace raychess;

std::vector<Position2D> Bishop::GetMoves(const BoardArea& board) const noexcept
{
    std::vector<Position2D> moves;
    moves.reserve(14);

    Position2D new_position;

    /*
     * The way this algorithm works is iterating over all possible directions using the two for
     * loops (each i, j pair could be considered a directional vector) and then adding the
     * directional vector to the current position until the new position is out of bounds or there
     * is a piece in the way. In case this piece is an enemy piece, the move is added to the list of
     * possible moves as well.
     */
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            // No need for a check here, the loop condition ensures that i and j are both either -1,
            // or 1.
            new_position = position_ + Position2D(i, j);
            // First check if the new tile is within bounds.
            while (board.IsWithinBounds(new_position)) {
                // If the given tile is free, add it to the list of possible moves.
                if (board.GetPieceAt(new_position) == nullptr) {
                    moves.push_back(new_position);
                }
                else {
                    // If the given tile is occupied, check whether it's occupied by an enemy piece.
                    // If so, attack is still possible.
                    if (board.GetPieceAt(new_position)->GetColour() != colour_) {
                        moves.push_back(new_position);
                    }
                    // At this point, a piece was in the way, block exploring this direction.
                    break;
                }
                new_position += Position2D(i, j);
            }
        }
    }

    return moves;
}

int Bishop::GetPointEvaulation(void) const noexcept { return 3; }
