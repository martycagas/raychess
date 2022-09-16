/**
 * @file    board_area.cpp
 *
 * @brief   Class representing a game board area.
 *
 * @section DESCRIPTION
 *
 * This class represents a chess board, manage its own state, size and pieces.
 */

#include "board_area.hpp"

using namespace raychess;

const std::vector<PieceBase>& BoardArea::GetPiecesByColour(
    PieceBase::PieceColour which_colour) const
{
    if (which_colour == PieceBase::PieceColour::WHITE) {
        return white_pieces_;
    }
    else if (which_colour == PieceBase::PieceColour::BLACK) {
        return black_pieces_;
    }
}

void BoardArea::AddPiece(PieceBase& piece)
{
    if (piece.GetColour() == PieceBase::PieceColour::WHITE) {
        white_pieces_.push_back(piece);
    }
    else if (piece.GetColour() == PieceBase::PieceColour::BLACK) {
        black_pieces_.push_back(piece);
    }
}

void BoardArea::ClearArea(void) noexcept
{
    white_pieces_.clear();
    black_pieces_.clear();
}

void BoardArea::RemovePiece(const Position2D& position, PieceBase::PieceColour colour)
{
    if (colour == PieceBase::PieceColour::WHITE) {
        for (auto it = white_pieces_.begin(); it != white_pieces_.end(); ++it) {
            if (it->GetPosition() == position) {
                white_pieces_.erase(it);
                break;
            }
        }
    }
    else if (colour == PieceBase::PieceColour::BLACK) {
        for (auto it = black_pieces_.begin(); it != black_pieces_.end(); ++it) {
            if (it->GetPosition() == position) {
                black_pieces_.erase(it);
                break;
            }
        }
    }
}

const PieceBase* BoardArea::GetPieceAt(const Position2D& position) const
{
    for (const auto& piece : white_pieces_) {
        if (piece.GetPosition() == position) {
            return &piece;
        }
    }
    for (const auto& piece : black_pieces_) {
        if (piece.GetPosition() == position) {
            return &piece;
        }
    }
    return nullptr;
}

const bool BoardArea::IsWithinBounds(const Position2D& position) const noexcept
{
    return (position.x >= 0 && position.x < dimension_x_ && position.y >= 0 &&
            position.y < dimension_y_);
}
