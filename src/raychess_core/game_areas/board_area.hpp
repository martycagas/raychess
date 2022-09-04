/**
 * @file    board_area.hpp
 *
 * @brief   Class representing a game board area.
 *
 * @section DESCRIPTION
 *
 * This class represents a chess board, manage its own state, size and pieces.
 */

#pragma once

#include <vector>

#include "area_base.hpp"
#include "piece_base.hpp"
#include "pos2d.hpp"

namespace raychess
{
    class BoardArea : public AreaBase
    {
    public:
        /**
         * @brief       Using the base class constructor.
         *
         * @see         AreaBase::AreaBase(int dimension_x, int dimension_y)
         */
        using AreaBase::AreaBase;

        /**
         * @brief       Motehod to get the pieces in the board area of the given colour.
         *
         * @see         AreaBase::GetPiecesByColour(PieceBase::PieceColour which_colour)
         *
         * @param[in]   which_colour  The colour of the pieces to get.
         *
         * @return      A const reference to the vector of pieces in the area.
         */
        const std::vector<PieceBase>& GetPiecesByColour(
            PieceBase::PieceColour which_colour) const override;

        /**
         * @brief       Method to add a piece to the board area.
         *
         * @see         AreaBase::AddPiece(PieceBase piece)
         *
         * @param[in]   piece  The piece to add to the area.
         */
        void AddPiece(PieceBase& piece) noexcept override;

        /**
         * @brief       Method to remove a piece from the board area.
         *
         * @see         AreaBase::RemovePiece(const Position2D& position,
         *                                    PieceBase::PieceColour colour)
         *
         * @param[in]   position  The position of the piece to remove.
         * @param[in]   colour    The colour of the piece to remove.
         */
        void RemovePiece(const Position2D& position,
                         PieceBase::PieceColour colour) noexcept override;

        /**
         * @brief       Method to remove all pieces from the area.
         *
         * @see         AreaBase::ClearArea()
         */
        void ClearArea(void) noexcept override;

        /**
         * @brief       Method to get a piece (if any) at the given position.
         *
         * @param[in]   position  The position to get the piece at.
         *
         * @return      A pointer to the piece at the given position, or nullptr if there is no
         * piece at the position.
         */
        const PieceBase* GetPieceAt(const Position2D& position) const;

    protected:
        std::vector<PieceBase> white_pieces_;  ///< Collection of white pieces in the area.
        std::vector<PieceBase> black_pieces_;  ///< Collection of black pieces in the area.
    };
}  // namespace raychess
