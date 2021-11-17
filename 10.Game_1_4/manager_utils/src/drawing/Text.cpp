// Corresponding header
#include "manager_utils/drawing/Text.h"
#include "manager_utils/managers/ResourceManager.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes

Text::~Text() {
    if (_isCreated && !_isDestroyed) {
        destroy();
    }
}

void Text::create(const std::string& text, int32_t fontId, const Color& color, const Point& pos) {
    if (_isCreated) {
        std::cerr << "Error, text with fontId " << fontId << " was already created." << std::endl;
        return;
    }

    gResourceMgr->createText(text, color, fontId, _drawParams.rsrcId, _drawParams.width, _drawParams.height);

    _drawParams.frameRect.x = 0;
    _drawParams.frameRect.y = 0;
    _drawParams.frameRect.w = _drawParams.width;
    _drawParams.frameRect.h = _drawParams.height;

    _drawParams.pos = pos;
    _drawParams.widgetType = WidgetType::TEXT;

    _textContent = text;
    _color = color;
    _fontId = fontId;

    _isCreated = true;
    _isDestroyed = false;
}

void Text::destroy() {
    if (!_isCreated) {
        std::cerr << "Error, text was already destroyed!" << std::endl;
        return;
    }

    _isCreated = false;
    _isDestroyed = true;

    Widget::reset();
}

void Text::setText(const std::string& text) {
    if (text == _textContent) {
        return;
    }

    _textContent = text;
    gResourceMgr->createText(text, _color, _fontId, _drawParams.rsrcId, _drawParams.width, _drawParams.height);

    _drawParams.frameRect.w = _drawParams.width;
    _drawParams.frameRect.h = _drawParams.height;
}

void Text::setColor(const Color& color) {
    if (color == _color) {
        return;
    }
    
    _color = color;
    gResourceMgr->createText(_textContent, color, _fontId, _drawParams.rsrcId, _drawParams.width, _drawParams.height);
}

std::string Text::getTextContent() const {
    return _textContent;
}
