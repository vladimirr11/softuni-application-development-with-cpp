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
    RUNNING_GIRL, 
    WHEEL, 
    START_BUTTON,
    STOP_BUTTON
};   
} // namespace TextureId 

namespace FontId {
enum FontIdKeys {
    ANGELINE_VINTAGE_40
};
} // namespace FontId

namespace TimerId {
enum Keys {
    WHEEL_ROTATION_ANIMATION_ID,
    SCALE_WHEEL_ID,
    RUNNING_GIRL_TIMER_ID
};
} // namespace TimerId


#endif // !COMMONDEFINES_H
