// Corresponding header
#include "includes/game/board/MoveSelector.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "includes/game/utility/BoardUtils.h"

int32_t MoveSelector::init(int32_t resourceId) {
    for (auto& image : _tileImgs) {
        image.create(resourceId);
    }

    return EXIT_SUCCESS;
}

void MoveSelector::draw() {
    for (size_t i = 0; i < _activeTiles; i++) {
        _tileImgs[i].draw();
    }
}

void MoveSelector::markTiles(const std::vector<TileData>& markedTiles) {
    _activeTiles = markedTiles.size();

    for (size_t i = 0; i < _activeTiles; i++) {
        _tileImgs[i].setPosition(BoardUtils::getAbsPos(markedTiles[i].boardPos));
        _tileImgs[i].setFrame(static_cast<int32_t>(markedTiles[i].tileType));
    }
}

void MoveSelector::unmarkTiles() {
    _activeTiles = 0;
}
