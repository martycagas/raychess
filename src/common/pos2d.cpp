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

Position2D::Position2D(Direction direction) noexcept
{
    switch (direction) {
        case Direction::UP:
            x = 0;
            y = 1;
            break;
        case Direction::DOWN:
            x = 0;
            y = -1;
            break;
        case Direction::LEFT:
            x = -1;
            y = 0;
            break;
        case Direction::RIGHT:
            x = 1;
            y = 0;
            break;
        case Direction::UP_LEFT:
            x = -1;
            y = 1;
            break;
        case Direction::UP_RIGHT:
            x = 1;
            y = 1;
            break;
        case Direction::DOWN_LEFT:
            x = -1;
            y = -1;
            break;
        case Direction::DOWN_RIGHT:
            x = 1;
            y = -1;
            break;
    }
}

inline Position2D Position2D::operator+(const Position2D &rhs) const
{
    return Position2D(x + rhs.x, y + rhs.y);
}

inline void Position2D::operator+=(const Position2D &rhs)
{
    x += rhs.x;
    y += rhs.y;
}

inline Position2D Position2D::operator-(const Position2D &rhs) const
{
    return Position2D(x - rhs.x, y - rhs.y);
}

inline void Position2D::operator-=(const Position2D &rhs)
{
    x -= rhs.x;
    y -= rhs.y;
}

inline bool Position2D::operator==(const Position2D &rhs) const
{
    return (x == rhs.x && y == rhs.y);
}

inline bool Position2D::operator!=(const Position2D &rhs) const
{
    return (x != rhs.x || y != rhs.y);
}
