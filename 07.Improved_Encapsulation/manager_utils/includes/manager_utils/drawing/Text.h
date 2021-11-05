#ifndef TEXT_H
#define TEXT_H

// C system includes

// C++ system includes
#include <cstdint>
#include <string>

// Third-party includes

// Own includes
#include "manager_utils/drawing/Widget.h"
#include "utils/drawing/Color.h"

//Forward declarations

class Text : public Widget {
public:
    ~Text();

    void create(const std::string& text, int32_t fontId, const Color& color, const Point& pos = Point::ZERO);
    void destroy();
    void setText(const std::string& text);
    void setColor(const Color& color);
    std::string getTextContent() const;

private:
    std::string _textContent;
    Color _color = Colors::BLACK;
    int32_t _fontId = RESOURCE_ID;
    bool _isDestroyed = false;
};

#endif // !TEXT_H
