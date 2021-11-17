#ifndef BOARDUTILS_H
#define BOARDUTILS_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "includes/game/utility/BoardPos.h"
#include "utils/drawing/Point.h"

// Forward declarations

class BoardUtils {
public:
    static BoardPosition getBoardPos(const Point& absPos);

    static Point getAbsPos(const BoardPosition& boardPos);

    static bool isInsideBoard(const BoardPosition& boardPos);
    static bool isInsideBoard(const Point& absPos);
};

#endif // !BOARDUTILS_H
