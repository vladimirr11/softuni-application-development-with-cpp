#ifndef GAMEBOARDPROXY_H
#define GAMEBOARDPROXY_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "includes/game/utility/BoardPos.h"

// Forward declarations

class GameBoardProxy {
public:
    virtual ~GameBoardProxy() = default;
    virtual void onPieceSelected(const BoardPosition& boardPos) = 0;
    virtual void onPieceReleased() = 0;
};

#endif // !GAMEBOARDPROXY_H
