#ifndef RESOURCEMANAGERCFG_H
#define RESOURCEMANAGERCFG_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "sdl_utils/config/TextContainerCfg.h"
#include "sdl_utils/config/ImageContainerCfg.h"

// Forward declarations

struct ResourceManagerConfig {
    ImageContainerConfig imageContainerCfg;
    TextContainerCfg textContainerCfg;
};

#endif // !RESOURCEMANAGERCFG_H
