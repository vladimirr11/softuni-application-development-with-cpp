#ifndef IMAGECONTAINERCFG_H
#define IMAGECONTAINERCFG_H

// C system includes

// C++ system includes
#include <cstdint>
#include <unordered_map>
#include <vector>

// Third-party includes

// Own includes
#include "utils/drawing/Rectangle.h"

//Forward declarations

struct ImageConfig {
    std::string location;
    std::vector<Rectangle> frames;
};

struct ImageContainerConfig {
    std::unordered_map<int32_t, ImageConfig> imageConfigs;
};

#endif // !IMAGECONTAINERCFG_H
