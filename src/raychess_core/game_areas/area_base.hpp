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
         * @brief       Pure virtual method to remove all pieces from the area.
         *
         * The derived classes can use a different storage method for various pieces.
         */
        virtual void ClearArea(void) noexcept = 0;

    protected:
        int dimension_x_;  ///< The x dimension of the area.
        int dimension_y_;  ///< The y dimension of the area.
    };
}  // namespace raychess
