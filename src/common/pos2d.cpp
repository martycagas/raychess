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

inline Position2D Position2D::operator+(const Direction2D &rhs) const noexcept
{
    switch (rhs) {
        case Direction2D::UP:
            return Position2D(x, y + 1);
        case Direction2D::DOWN:
            return Position2D(x, y - 1);
        case Direction2D::LEFT:
            return Position2D(x - 1, y);
        case Direction2D::RIGHT:
            return Position2D(x + 1, y);
        case Direction2D::UP_LEFT:
            return Position2D(x - 1, y + 1);
        case Direction2D::UP_RIGHT:
            return Position2D(x + 1, y + 1);
        case Direction2D::DOWN_LEFT:
            return Position2D(x - 1, y - 1);
        case Direction2D::DOWN_RIGHT:
            return Position2D(x + 1, y - 1);
    }
}

inline void Position2D::operator+=(const Position2D &rhs)
{
    x += rhs.x;
    y += rhs.y;
}

inline void Position2D::operator+=(const Direction2D &rhs)
{
    switch (rhs) {
        case Direction2D::UP:
            y += 1;
            break;
        case Direction2D::DOWN:
            y -= 1;
            break;
        case Direction2D::LEFT:
            x -= 1;
            break;
        case Direction2D::RIGHT:
            x += 1;
            break;
        case Direction2D::UP_LEFT:
            x -= 1;
            y += 1;
            break;
        case Direction2D::UP_RIGHT:
            x += 1;
            y += 1;
            break;
        case Direction2D::DOWN_LEFT:
            x -= 1;
            y -= 1;
            break;
        case Direction2D::DOWN_RIGHT:
            x += 1;
            y -= 1;
            break;
    }
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
