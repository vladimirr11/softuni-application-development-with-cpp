#ifndef DRAWMANAGERCFG_H
#define DRAWMANAGERCFG_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "sdl_utils/config/MonitorWindowCfg.h"

// Forward declarations

struct DrawManagerCfg {
    MonitorWindowCfg windowConfig;
    int64_t maxFrameRate;
};

#endif // !DRAWMANAGERCFG_H
