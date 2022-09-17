/**
 * @file    capture_area.cpp
 *
 * @brief   Class representing a game capture area.
 *
 * @section DESCRIPTION
 *
 * This class represents one of the two capture areas; one for each player.
 */

#include "capture_area.hpp"

using namespace raychess;

const std::vector<PieceBase>& CaptureArea::GetPiecesByColour(
    PieceBase::PieceColour which_colour) const
{
    return pieces_;
}

void CaptureArea::AddPiece(PieceBase& piece) noexcept { pieces_.push_back(piece); }

void CaptureArea::ClearArea(void) noexcept { pieces_.clear(); }

void CaptureArea::SortPieces(void) noexcept
{
    std::sort(pieces_.begin(), pieces_.end(), [](const PieceBase& lhs, const PieceBase& rhs) {
        return lhs.GetPointEvaulation() < rhs.GetPointEvaulation();
    });
}
