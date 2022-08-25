/**
 * @file    queen.hpp
 *
 * @brief   Class representing a queen.
 *
 * @section DESCRIPTION
 *
 * Class representing a queen chess piece with its own unique behaviour.
 */

#pragma once

#include <vector>

#include "piece_base.hpp"
#include "pos2d.hpp"

namespace raychess
{
    class Queen : public PieceBase
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
         * @brief       Using the default implementation of the GetAttackOnlyMoves method.
         *
         * @see         PieceBase::GetAttackOnlyMoves(void)
         */
        using PieceBase::GetAttackOnlyMoves;

        /**
         * @brief       Using the default implementation of the Move method.
         *
         * @see         PieceBase::Move(Position2D new_position)
         */
        using PieceBase::Move;
    };
}  // namespace raychess
