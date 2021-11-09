#ifndef MANAGERHANDLERCFG_H
#define MANAGERHANDLERCFG_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "manager_utils/managers/config/DrawManagerCfg.h"
#include "manager_utils/managers/config/ResourceManagerCfg.h"

// Forward declarations

struct ManagerHandlerCfg {
    DrawManagerCfg drawManagerCfg;
    ResourceManagerCfg resourceManagerCfg;
};

#endif // !MANAGERHANDLERCFG_H
