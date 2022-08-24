/**
 * @file    pos2d.hpp
 *
 * @brief   A class to represent a 2D position.
 *
 * @section DESCRIPTION
 *
 * A temporary class to represent a discrete 2D position with some accompanying methods.
 */

#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>

namespace raychess
{
    /**
     * @brief   A class to represent a 2D position.
     *
     * A class to represent a discrete 2D position with some accompanying methods.
     *
     * Following chess conventions, the origin is the bottom left corner. In other words,
     * Position2D(0, 0) is equivalent to A1 in chess notation. This is important for proper usage of
     * the nested enum class Position2D::Direction2D.
     */
    struct Position2D
    {
        enum class Direction2D
        {
            UP,
            DOWN,
            LEFT,
            RIGHT,
            UP_LEFT,
            UP_RIGHT,
            DOWN_LEFT,
            DOWN_RIGHT
        };

        int x;  ///< The X component.
        int y;  ///< The Y component.

        /**
         * @brief       Default constructor. Initializes to (0, 0).
         */
        Position2D() noexcept;

        /**
         * @brief       Constructor. Initializes to (xy, xy).
         *
         * @param[in]   xy  The value to initialize both components to.
         */
        Position2D(int xy) noexcept;

        /**
         * @brief       Constructor. Initializes to (x, y).
         *
         * @param[in]   x  The X component.
         * @param[in]   y  The Y component.
         */
        Position2D(int x, int y) noexcept;

        /**
         * @brief       Direction-based constructor. Initializes to (0, 0) + direction.
         *
         * @param[in]   direction  The Position2D::Direction2D to initialize to.
         */
        Position2D(Direction2D direction) noexcept;

        /**
         * @brief       Adds another Position2D to this one and returns the result.
         *
         * @param[in]   rhs  The Position2D to add.
         *
         * @return      A new Position2D with the result of the addition.
         */
        inline Position2D operator+(const Position2D &rhs) const noexcept;

        /**
         * @brief       Adds a Position2D::Direction2D to this one and returns the result. Saves
         * having to create a new Position2D from Position2D::Direction2D.
         *
         * @param[in]   rhs  The Position2D::Direction2D to add.
         *
         * @return      A new Position2D with the result of the addition.
         */
        inline Position2D operator+(const Direction2D &rhs) const noexcept;

        /**
         * @brief       Adds another Position2D to this one.
         *
         * @param[in]   rhs  The Position2D to add.
         */
        inline void operator+=(const Position2D &rhs) noexcept;

        /**
         * @brief       Adds a Position2D::Direction2D to this one. Saves having to create a new
         * Position2D from Position2D::Direction2D.
         *
         * @param[in]   rhs  The Position2D::Direction2D to add.
         */
        inline void operator+=(const Direction2D &rhs) noexcept;

        /**
         * @brief       Subtracts another Position2D from this one and returns the result.
         *
         * @param[in]   rhs  The Position2D to subtract.
         *
         * @return      A new Position2D with the result of the subtraction.
         */
        inline Position2D operator-(const Position2D &rhs) const noexcept;

        /**
         * @brief       Subtracts another Position2D from this one.
         *
         * @param[in]   rhs  The Position2D to subtract.
         */
        inline void operator-=(const Position2D &rhs) noexcept;

        /**
         * @brief       Compares this Position2D to another.
         *
         * @param[in]   rhs  The Position2D to compare to.
         *
         * @return      True if the two Position2Ds are equal, false otherwise.
         */
        inline bool operator==(const Position2D &rhs) const noexcept;

        /**
         * @brief       Compares this Position2D to another.
         *
         * @param[in]   rhs  The Position2D to compare to.
         *
         * @return      True if the two Position2Ds are not equal, false otherwise.
         */
        inline bool operator!=(const Position2D &rhs) const noexcept;
    };
}  // namespace raychess
