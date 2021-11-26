#ifndef DRAWPARAMS_H
#define DRAWPARAMS_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/drawing/Point.h"
#include "utils/drawing/Rectangle.h"

//Forward declarations

inline constexpr auto INVALID_RESOURCE_ID = -1;
inline constexpr int32_t FULL_OPACITY = 255;
inline constexpr int32_t ZERO_OPACITY = 0;
inline constexpr double FULL_ROTATION = 360.0;

enum class WidgetFlip : uint8_t {
    NONE,
    HORIZONTAL,
    VERTICAL,
    HORIZONTAL_AND_VERTICAL
};

enum class WidgetType : uint8_t {
    IMAGE,
    TEXT,
    UNKNOWN
};

enum class BlendMode : uint8_t {
    NONE = 0, // value for SDL_BLENDMODE_NONE
    BLEND = 1, // value for SDL_BLENDMODE_BLEND
    ADD = 2, // value for SDL_BLENDMODE_ADD
    MOD = 4 // value for SDL_BLENDMODE_MODE
};

struct DrawParams {
    void reset();
    
    Point pos = Point::UNDEFINED;
    Rectangle frameRect = Rectangle::ZERO;
    
    // Draw dimensions of the texture
    int32_t width = 0;
    int32_t height = 0;

    double rotationAngle = 0.0;
    
    Point rotationCenter = Point::ZERO;
    
    int32_t opacity = FULL_OPACITY;
    
    // unique resourceId and textId
    union {
        int32_t rsrcId = INVALID_RESOURCE_ID;
        int32_t textId;
    };
    
    WidgetType widgetType = WidgetType::UNKNOWN;

    WidgetFlip widgetFlip = WidgetFlip::NONE;
};

#endif // !DRAWPARAMS_H
