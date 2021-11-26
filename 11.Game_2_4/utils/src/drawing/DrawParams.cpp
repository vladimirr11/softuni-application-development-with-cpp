// Corresponding header
#include "utils/drawing/DrawParams.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes

void DrawParams::reset() {
    frameRect = Rectangle::ZERO;
    pos = Point::UNDEFINED;
    
    width = 0;
    height = 0;

    rotationAngle = 0.0;
    
    opacity = FULL_OPACITY;
    
    rsrcId = INVALID_RESOURCE_ID;
    
    widgetType = WidgetType::UNKNOWN;

    widgetFlip = WidgetFlip::NONE;
}
