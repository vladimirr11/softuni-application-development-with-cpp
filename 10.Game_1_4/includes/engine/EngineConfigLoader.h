#ifndef ENGINECONFIGLOADER_H
#define ENGINECONFIGLOADER_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "includes/engine/config/EngineConfig.h"

// Forward declarations

class EngineConfigLoader {
public:
    EngineConfigLoader() = delete;
    ~EngineConfigLoader() = default;

    static EngineConfig loadConfig();
};

#endif // !ENGINECONFIGLOADER_H
