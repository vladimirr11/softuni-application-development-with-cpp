#ifndef POINT_H
#define POINT_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations

struct Point {
    Point() = default;
    Point(int32_t inputX, int32_t inputY);

    int32_t x = 0;
    int32_t y = 0;

    static const Point ZERO;
    static const Point UNDEFINED;

    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
};

#endif // !POINT_H
