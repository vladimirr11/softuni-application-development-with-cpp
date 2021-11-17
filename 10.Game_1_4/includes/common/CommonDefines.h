#ifndef COMMONDEFINES_H
#define COMMONDEFINES_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations

namespace TextureId {
enum ResourceId { 
    CHESS_BOARD, 
    TARGET,
    WHITE_PIECES,
    BLACK_PIECES
};   
} // namespace TextureId 

namespace FontId {
enum FontIdKeys {
    ANGELINE_VINTAGE
};
} // namespace FontId

namespace TimerId {
enum Keys {
    BLINK_TARGET_TIMER_ID
};
} // namespace TimerId


#endif // !COMMONDEFINES_H
