/**
 * @file    piece_base.hpp
 *
 * @brief   Base class representing a chess piece.
 *
 * @section DESCRIPTION
 *
 * This abstract class aims to provide a basic interface of methods a piece should support.
 */

#pragma once

#include <vector>

#include "pos2d.hpp"

namespace raychess
{
    class PieceBase
    {
    public:
        /**
         * @brief   Structure representing a piece color.
         */
        enum class PieceColour
        {
            WHITE,
            BLACK
        };

        /**
         * @brief       Constructor.
         *
         * @param[in]   colour  The color of the piece.
         */
        PieceBase(PieceColour colour, Position2D position) noexcept
            : colour_(colour), position_(position){};

        /**
         * @brief       Colour getter.
         *
         * @return      The colour of the piece.
         */
        PieceColour GetColour(void) noexcept { return colour_; }

        /**
         * @brief       Position getter.
         *
         * @return      The position of the piece.
         */
        Position2D GetPosition(void) noexcept { return position_; }

        /**
         * @brief       Get a vector of all possible moves for the piece.
         *
         * Gets a vector of all possible moves for the piece. Not all moves on this vector are
         * guaranteed to be valid moves. It's up to the game (usually a board) that has the
         * information about other pieces to classivy the moves as valid, invalid or attack moves.
         *
         * @return      A vector of all possible moves for the piece.
         */
        virtual std::vector<Position2D> GetMoves(void) noexcept = 0;

        /**
         * @brief       Get a vector of all possible moves for the piece, that can only end with an
         * attack.
         *
         * This method is needed to support the pawns.
         *
         * @return      A vector of all possible attack-only moves for the piece.
         */
        virtual std::vector<Position2D> GetAttackOnlyMoves(void) noexcept { return {}; }

        /**
         * @brief       Moves the piece to a new position.
         *
         * @param[in]   new_position  The new position of the piece.
         */
        virtual void Move(Position2D new_position) noexcept { position_ = new_position; }

    protected:
        PieceColour colour_;   ///< The colour of the piece.
        Position2D position_;  ///< The position of the piece.
    };
}  // namespace raychess
