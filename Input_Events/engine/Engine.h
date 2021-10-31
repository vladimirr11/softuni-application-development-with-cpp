#ifndef ENGINE_H
#define ENGINE_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "sdl_utils/InputEvent.h"
#include "sdl_utils/MonitorWindow.h"

// Forward declarations

enum Images {
    UP, DOWN, LEFT, RIGHT, ALL_KEYS, COUNT
};

class Engine {
public:
    int32_t init();
    void deinit();
    void start();

private:
    int32_t loadResources();

    void mainLoop();
    void drawFrame();
    bool processFrame();
    void handleEvent();

    void limitFPS(int64_t microsecondsToSleepFor);

    MonitorWindow _window;
    InputEvent _event;
    SDL_Surface* _screenSurface = nullptr;

    // game specific logic
    SDL_Surface* _currChosenImage = nullptr;
    SDL_Surface* _imageSurfaces[COUNT] {};

};

#endif // !ENGINE_H
