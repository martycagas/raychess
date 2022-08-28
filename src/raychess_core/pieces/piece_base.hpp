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
         * @brief   Structure representing a piece colour.
         */
        enum class PieceColour
        {
            WHITE,
            BLACK,
            ANY
        };

        /**
         * @brief       Constructor.
         *
         * @param[in]   colour  The colour of the piece.
         */
        PieceBase(PieceColour colour, Position2D position) noexcept
            : colour_(colour), position_(position){};

        /**
         * @brief       Colour getter.
         *
         * @return      The colour of the piece.
         */
        PieceColour GetColour(void) const noexcept { return colour_; }

        /**
         * @brief       Position getter.
         *
         * @return      The position of the piece.
         */
        Position2D GetPosition(void) const noexcept { return position_; }

        /**
         * @brief       Get a vector of all possible moves for the piece.
         *
         * Gets a vector of all possible moves for the piece. Not all moves on this vector are
         * guaranteed to be valid moves. It's up to the game (usually a board) that has the
         * information about other pieces to classivy the moves as valid, invalid or attack moves.
         *
         * @return      A vector of all possible moves for the piece.
         */
        virtual std::vector<Position2D> GetMoves(void) const noexcept = 0;

        /**
         * @brief       Moves the piece to a new position.
         *
         * @param[in]   new_position  The new position of the piece.
         */
        virtual void Move(Position2D new_position) noexcept { position_ = new_position; }

        /**
         * @brief       Pure virtual method to get the point evaluation of the piece.
         *
         * All pieces have value. This method must be implemented by the derived classes so there is
         * no point making this method not a pure virtual one. There is no point in a default
         * implementation.
         *
         * The point values can be seen below:
         *
         * - Pawn: 1
         * - Knight: 3
         * - Bishop: 3
         * - Rook: 5
         * - Queen: 9
         *
         * @return      The point evaluation of the piece.
         */
        virtual int GetPointEvaulation(void) const noexcept = 0;

        /**
         * @brief       Get a vector of all possible moves for the piece, that can only end with an
         * attack.
         *
         * Applies onlly to pawns.
         *
         * @return      A vector of all possible attack-only moves for the piece.
         */
        virtual std::vector<Position2D> GetAttackOnlyMoves(void) const noexcept { return {}; }

        /**
         * @brief       Checks if the piece can make an en passant move.
         *
         * Applies only to pawns.
         *
         * @return      True if the piece can make an en passant move, false otherwise.
         */
        virtual bool CanEnPassant(void) const noexcept { return false; }

        /**
         * @brief       Checks if the piece can be promoted.
         *
         * Applies only to pawns.
         *
         * @return      True if the piece can be promoted, false otherwise.
         */
        virtual bool CanBePromoted(void) const noexcept { return false; }

        /**
         * @brief       Checks if the piece can move two squares forward.
         *
         * Applies only to pawns.
         *
         * @return      True if the piece can move two squares forward, false otherwise.
         */
        virtual bool CanMoveTwoSquares(void) const noexcept { return false; }

    protected:
        PieceColour colour_;   ///< The colour of the piece.
        Position2D position_;  ///< The position of the piece.
    };
}  // namespace raychess
