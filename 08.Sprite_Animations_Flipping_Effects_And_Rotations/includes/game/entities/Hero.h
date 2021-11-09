#ifndef HERO_H
#define HERO_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "manager_utils/drawing/Image.h"

// Forward declarations
struct InputEvent;

class Hero {
public:
    int32_t init(int32_t resourceId);

    void deinit();

    void draw();

    void handleEvent(const InputEvent& event);

private:
    Image _heroImg;
};

#endif // !HERO_H
