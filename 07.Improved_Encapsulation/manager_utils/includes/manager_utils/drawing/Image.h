#ifndef IMAGE_H
#define IMAGE_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "manager_utils/drawing/Widget.h"

//Forward declarations

class Image : public Widget {
public:
    ~Image();

    void create(int32_t resourceId, const Point& pos = Point::ZERO);

    void destroy();
};

#endif // !IMAGE_H
