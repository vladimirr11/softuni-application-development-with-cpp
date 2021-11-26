// Corresponding header
#include "manager_utils/managers/ManagerHandler.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "manager_utils/managers/DrawManager.h"
#include "manager_utils/managers/ResourceManager.h"
#include "manager_utils/managers/config/ManagerHandlerCfg.h"
#include "manager_utils/managers/TimerManager.h"

int32_t ManagerHandler::init(const ManagerHandlerConfig& managerHandlerCfg) {
    gDrawManager = new DrawManager();
    if (gDrawManager == nullptr) {
        std::cerr << "Error, bad allocation for DrawManager!" << std::endl;
        return EXIT_FAILURE;
    }

    if (gDrawManager->init(managerHandlerCfg.drawManagerCfg) != EXIT_SUCCESS) {
        std::cerr << "gDrawManager->init() failed in ManagerHandler::init()!" << std::endl;
        return EXIT_FAILURE;
    }

    gResourceManager = new ResourceManager();
    if (gResourceManager == nullptr) {
        std::cerr << "Error, bad allocation for ResourceManager!" << std::endl;
        return EXIT_FAILURE;
    }

    if (gResourceManager->init(managerHandlerCfg.resourceManagerCfg) != EXIT_SUCCESS) {
        std::cerr << "gResourceMgr->init() failed in ManagerHandler::init()!" << std::endl;
        return EXIT_FAILURE;
    }

    gTimerManager = new TimerManager();
    if (gTimerManager == nullptr) {
        std::cerr << "Error, bad allocation for TimerManager!" << std::endl;
        return EXIT_FAILURE;
    }

    if (gTimerManager->init() != EXIT_SUCCESS) {
        std::cerr << "gTimerManager->init() failed in ManagerHandler::init()!" << std::endl;
        return EXIT_FAILURE;
    }

    _managers[DRAW_MANAGER_IDX] = static_cast<ManagerBase*>(gDrawManager);
    _managers[RESOURCE_MANAGER_IDX] = static_cast<ManagerBase*>(gResourceManager);
    _managers[TIMER_MANAGER_IDX] = static_cast<ManagerBase*>(gTimerManager);

    return EXIT_SUCCESS;
}

void ManagerHandler::deinit() {
    for (int32_t i = MANAGERS_COUNT - 1; i >= 0; i--) {
        _managers[i]->deinit();
        _managers[i] = nullptr;
        nullifyGlobalManager(i);
    }
}

void ManagerHandler::process() {
    for (int32_t i = 0; i < MANAGERS_COUNT; i++) {
        _managers[i]->process();
    }
}

void ManagerHandler::nullifyGlobalManager(int32_t managerIdx) {
    switch (managerIdx) {
    case DRAW_MANAGER_IDX:
        delete gDrawManager;
        gDrawManager = nullptr;
        break;
    case RESOURCE_MANAGER_IDX:
        delete gResourceManager;
        gResourceManager = nullptr;
        break;
    case TIMER_MANAGER_IDX:
        delete gTimerManager;
        gTimerManager = nullptr;
        break;

    default:
        std::cerr << "Recieved invalid managerIdx!" << std::endl;
        break;
    }
}
