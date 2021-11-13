#ifndef ENGINE_H
#define ENGINE_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "includes/game/Game.h"
#include "sdl_utils/InputEvent.h"
#include "manager_utils/managers/ManagerHandler.h"

// Forward declarations
struct EngineConfig;

class Engine {
public:
    int32_t init(const EngineConfig& cfg);
    void deinit();
    void start();

private:
    void mainLoop();
    void drawFrame();
    bool processFrame();
    void handleEvent();

    void limitFPS(int64_t microsecondsToSleepFor);

    ManagerHandler _managerHandler;
    InputEvent _event;
    Game _game;
};

#endif // !ENGINE_H
