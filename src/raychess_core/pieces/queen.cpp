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

std::vector<Position2D> Queen::GetMoves(const BoardArea& board) const noexcept
{
    std::vector<Position2D> moves;
    moves.reserve(28);

    Position2D new_position;

    /*
     * The way this algorithm works is iterating over all possible directions using the two for
     * loops (each i, j pair could be considered a directional vector) and then adding the
     * directional vector to the current position until the new position is out of bounds or there
     * is a piece in the way. In case this piece is an enemy piece, the move is added to the list of
     * possible moves as well.
     */
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            new_position = position_ + Position2D(i, j);
            // First check if the new tile is within bounds.
            while (!new_position.IsOutOfBounds(board.GetDimensionX(), board.GetDimensionY())) {
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

int Queen::GetPointEvaulation(void) const noexcept { return 9; }
