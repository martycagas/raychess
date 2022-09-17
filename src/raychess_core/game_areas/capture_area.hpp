/**
 * @file    capture_area.hpp
 *
 * @brief   Class representing a game capture area.
 *
 * @section DESCRIPTION
 *
 * This class represents one of the two capture areas; one for each player.
 */

#pragma once

#include <algorithm>
#include <vector>

#include "area_base.hpp"
#include "piece_base.hpp"
#include "pos2d.hpp"

namespace raychess
{
    class CaptureArea : public AreaBase
    {
    public:
        /**
         * @brief       Using the base class constructor.
         *
         * @see         AreaBase::AreaBase(int dimension_x, int dimension_y)
         */
        using AreaBase::AreaBase;

        /**
         * @brief       Motehod to get the pieces in the capture area.
         *
         * @see         AreaBase::GetPiecesByColour(PieceBase::PieceColour which_colour)
         *
         * @param[in]   which_colour  The colour of the pieces to get. This paramter is ignored for
         * a capture area.
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
         * @brief       Pure virtual method to remove all pieces from the area.
         *
         * @see         AreaBase::ClearArea()
         */
        void ClearArea(void) noexcept override;

        /**
         * @brief       Method to sort the pieces in the area.
         *
         * Sorts the pieces in the area according to their point evaluation.
         */
        void SortPieces(void) noexcept { return; }

    protected:
        std::vector<PieceBase> pieces_;  ///< Collection of captured pieces.
    };
}  // namespace raychess
