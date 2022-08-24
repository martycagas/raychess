/**
 * @file    pos2d.cpp
 *
 * @brief   A class to represent a 2D position.
 *
 * @section DESCRIPTION
 *
 * A temporary class to represent a discrete 2D position with some accompanying methods.
 */

#include "pos2d.hpp"

using namespace raychess;

Position2D::Position2D() noexcept : x(0), y(0) {}

Position2D::Position2D(int xy) noexcept : x(xy), y(xy) {}

Position2D::Position2D(int x, int y) noexcept : x(x), y(y) {}

Position2D::Position2D(Direction2D direction) noexcept
{
    switch (direction) {
        case Direction2D::UP:
            x = 0;
            y = 1;
            break;
        case Direction2D::DOWN:
            x = 0;
            y = -1;
            break;
        case Direction2D::LEFT:
            x = -1;
            y = 0;
            break;
        case Direction2D::RIGHT:
            x = 1;
            y = 0;
            break;
        case Direction2D::UP_LEFT:
            x = -1;
            y = 1;
            break;
        case Direction2D::UP_RIGHT:
            x = 1;
            y = 1;
            break;
        case Direction2D::DOWN_LEFT:
            x = -1;
            y = -1;
            break;
        case Direction2D::DOWN_RIGHT:
            x = 1;
            y = -1;
            break;
    }
}

inline Position2D Position2D::operator+(const Position2D &rhs) const noexcept
{
    return Position2D(x + rhs.x, y + rhs.y);
}

inline void Position2D::operator+=(const Position2D &rhs) noexcept
{
    x += rhs.x;
    y += rhs.y;
}

inline Position2D Position2D::operator-(const Position2D &rhs) const noexcept
{
    return Position2D(x - rhs.x, y - rhs.y);
}

inline void Position2D::operator-=(const Position2D &rhs) noexcept
{
    x -= rhs.x;
    y -= rhs.y;
}

inline Position2D Position2D::operator*(const int &rhs) const noexcept
{
    return Position2D(x * rhs, y * rhs);
}

inline void Position2D::operator*=(const int &rhs) noexcept
{
    x *= rhs;
    y *= rhs;
}

inline bool Position2D::operator==(const Position2D &rhs) const noexcept
{
    return (x == rhs.x && y == rhs.y);
}

inline bool Position2D::operator!=(const Position2D &rhs) const noexcept
{
    return (x != rhs.x || y != rhs.y);
}

inline bool Position2D::IsOutOfBounds(const int dim_x, const int dim_y) const noexcept
{
    return (x < 0 || x >= dim_x || y < 0 || y >= dim_y);
}
