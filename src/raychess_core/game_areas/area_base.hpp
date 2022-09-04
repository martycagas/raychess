/**
 * @file    area_base.hpp
 *
 * @brief   Base class representing a game area.
 *
 * @section DESCRIPTION
 *
 * This abstract class aims to provide a basic interface of methods a game area should support, such
 * as keeping track of pieces in the area.
 */

#pragma once

#include <vector>

#include "piece_base.hpp"
#include "pos2d.hpp"

namespace raychess
{
    class AreaBase
    {
    public:
        /**
         * @brief       Constructor.
         *
         * @param[in]   dimension_x  The x dimension of the area.
         * @param[in]   dimension_y  The y dimension of the area.
         */
        AreaBase(int dimension_x, int dimension_y) noexcept
            : dimension_x_(dimension_x), dimension_y_(dimension_y){};

        /**
         * @brief       X-axis dimension getter.
         *
         * @return      The X-axis dimension of the area.
         */
        int GetDimensionX(void) const noexcept { return dimension_x_; }

        /**
         * @brief       Y-axis dimension getter.
         *
         * @return      The Y-axis dimension of the area.
         */
        int GetDimensionY(void) const noexcept { return dimension_y_; }

        /**
         * @brief       Pure virtual motehod to get the pieces in the area of the given colour.
         *
         * @param[in]   which_colour  The colour of the pieces to get.
         *
         * @return      A const reference to the vector of pieces in the area.
         */
        virtual const std::vector<PieceBase>& GetPiecesByColour(
            PieceBase::PieceColour which_colour) const noexcept = 0;

        /**
         * @brief       Virtual method to get a piece (if any) at the given position.
         *
         * @param[in]   position  The position to get the piece at.
         *
         * @return      A pointer to the piece at the given position, or nullptr if there is no
         * piece at the position.
         */
        virtual const PieceBase* GetPieceAt(const Position2D& position) const noexcept
        {
            return nullptr;
        }

        /**
         * @brief       Pure virtual method to add a piece to the area.
         *
         * It's up to the derived class to decide where and how to store pieces and how to add them.
         * Also, passing the colour information is unnecessary as the piece already contains this
         * information, but the derived class may not need that information in the first place.
         *
         * @param[in]   piece  The piece to add.
         */
        virtual void AddPiece(PieceBase& piece) noexcept = 0;

        /**
         * @brief       Pure virtual method to remove a piece from the area on the given position.
         *
         * It's up to the derived class to decide where and how to remove pieces.
         *
         * @param[in]   position  The position of the piece to remove.
         * @param[in]   colour    The colour of the piece to remove. Defaults to
         *                        PieceBase::PieceColour::ANY.
         */
        virtual void RemovePiece(
            const Position2D& position,
            PieceBase::PieceColour colour = PieceBase::PieceColour::ANY) noexcept = 0;

        /**
         * @brief       Virtual method to sort the pieces in the area.
         *
         * This method is virtual but not pure virtual. As such, it should be overridden by derived
         * classes if and only if those areas are meant to be sorted.
         *
         * Example of an area that should never be sorted: board area.
         *
         * Example of an area that can - but does not have to - be sorted: capture area.
         */
        virtual void SortPieces(void) noexcept { return; }

    protected:
        int dimension_x_;  ///< The x dimension of the area.
        int dimension_y_;  ///< The y dimension of the area.
    };
}  // namespace raychess
