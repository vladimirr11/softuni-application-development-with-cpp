// Corresponding header
#include "manager_utils/drawing/Image.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "manager_utils/managers/ResourceManager.h"

Image::~Image() {
    if (_isCreated && !_isDestroyed) {
        destroy();
    }
}

void Image::create(int32_t resourceId, const Point& pos) {
    if (_isCreated) {
        std::cerr << "Error, image with resourceId " << resourceId << " was already created." << std::endl;
        return;
    }

    const Rectangle rect = gResourceMgr->getImageFrame(resourceId);
    
    _drawParams.rsrcId = resourceId;
    _drawParams.width = rect.w;
    _drawParams.height = rect.h;
    _drawParams.pos = pos;
    _drawParams.widgetType = WidgetType::IMAGE;

    _isCreated = true;
    _isDestroyed = false;
}

void Image::destroy() {
    if (!_isCreated) {
        std::cerr << "Error, image was already destroyed!" << std::endl;
        return;
    }

    _isCreated = false;
    _isDestroyed = true;

    Widget::reset();
}
