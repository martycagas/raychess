/**
 * @file    pawn.hpp
 *
 * @brief   Class representing a pawn.
 *
 * @section DESCRIPTION
 *
 * Class representing a pawn chess piece with its own unique behaviour.
 */

#pragma once

#include <vector>

#include "piece_base.hpp"
#include "pos2d.hpp"

namespace raychess
{
    class Pawn : public PieceBase
    {
    public:
        /**
         * @brief       Using the base class constructor.
         *
         * @see         PieceBase::PieceBase(PieceColour colour, Position2D position)
         */
        using PieceBase::PieceBase;

        /**
         * @brief       Get a vector of all possible moves for the piece.
         *
         * @see         PieceBase::GetMoves()
         *
         * @return      A vector of all possible moves for the piece.
         */
        std::vector<Position2D> GetMoves(void) noexcept override;

        /**
         * @brief       Get a vector of all possible moves for the piece, that can only end with an
         * attack.
         *
         * @see         PieceBase::GetAttackOnlyMoves()
         *
         * @return      A vector of all possible attack-only moves for the piece.
         */
        std::vector<Position2D> GetAttackOnlyMoves(void) noexcept override;

        /**
         * @brief       Moves the piece to the given position while marking the piece as moved.
         *
         * @param[in]   new_position  The new position of the piece.
         */
        void Move(Position2D new_position) noexcept override;

        /**
         * @brief       Checks if the piece can be promoted.
         *
         * @return      True if the piece can be promoted, false otherwise.
         */
        bool CanBePromoted(void) const noexcept;

    private:
        bool has_moved_;
    };
}  // namespace raychess
