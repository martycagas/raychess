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
    class Pawn final : public PieceBase
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
        std::vector<Position2D> GetMoves(void) const noexcept override;

        /**
         * @brief       Moves the piece to the given position while marking the piece as moved.
         *
         * @param[in]   new_position  The new position of the piece.
         */
        void Move(Position2D new_position) noexcept override;

        /**
         * @brief       Get the point evaluation of the piece.
         *
         * @see         PieceBase::GetPointEvaulation()
         *
         * @return      The point evaluation of the piece.
         */
        int GetPointEvaulation(void) const noexcept override;

        /**
         * @brief       Get a vector of all possible moves for the piece, that can only end with an
         * attack.
         *
         * @see         PieceBase::GetAttackOnlyMoves()
         *
         * @return      A vector of all possible attack-only moves for the piece.
         */
        std::vector<Position2D> GetAttackOnlyMoves(void) const noexcept override;

        /**
         * @brief       Checks if the piece can make an en passant move.
         *
         * @return      True if the piece can make an en passant move, false otherwise.
         */
        bool CanEnPassant(void) const noexcept override;

        /**
         * @brief       Checks if the piece can be promoted.
         *
         * @return      True if the piece can be promoted, false otherwise.
         */
        bool CanBePromoted(void) const noexcept override;

        /**
         * @brief       Checks if the piece can move two squares forward.
         *
         * @return      True if the piece can move two squares forward, false otherwise.
         */
        bool CanMoveTwoSquares(void) const noexcept override;

    private:
        bool has_moved_;
    };
}  // namespace raychess
