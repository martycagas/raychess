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
            : dimension_x_(dimension_x), dimension_y_(dimension_y), pieces_(){};

        /**
         * @brief       X dimension getter.
         *
         * @return      The x dimension of the area.
         */
        int GetDimensionX(void) noexcept { return dimension_x_; }

        /**
         * @brief       Y dimension getter.
         *
         * @return      The y dimension of the area.
         */
        int GetDimensionY(void) noexcept { return dimension_y_; }

        /**
         * @brief       Get a reference to the vector of pieces in the area.
         *
         * @return      A reference to the vector of pieces in the area.
         */
        std::vector<PieceBase>& GetPieces(void) noexcept { return pieces_; }

        /**
         * @brief Virtual method to sort the pieces in the area.
         *
         * This method is virtual but not pure virtual. As such, it should be overridden by derived
         * classes if and only if those areas are meant to be sorted.
         *
         * Example of an area that should never be sorted: board area.
         *
         * Example of an area that can - but does not have to - be sorted: capture area.
         */
        virtual void SortPieces(void) noexcept { return; };

    private:
        int dimension_x_;  ///< The x dimension of the area.
        int dimension_y_;  ///< The y dimension of the area.

        std::vector<PieceBase> pieces_;  ///< The pieces in the area.
    };
}  // namespace raychess
