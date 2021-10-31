#ifndef RECTANGLE_H
#define RECTANGLE_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations
struct Point;

struct Rectangle {
public:
    Rectangle() = default;
    Rectangle(int32_t inputX, int32_t inputY, int32_t inputWidth, int32_t inputHeight);

    int32_t x = 0;
    int32_t y = 0;
    int32_t w = 0;
    int32_t h = 0;

    static const Rectangle ZERO;
    static const Rectangle UNDEFINED;

    bool isPointInsideRect(const Point& point) const;

    bool operator==(const Rectangle& other) const;
    bool operator!=(const Rectangle& other) const;
};

#endif // !RECTANGLE_H
