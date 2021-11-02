#ifndef ENGINE_H
#define ENGINE_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "game/Game.h"
#include "sdl_utils/InputEvent.h"
#include "sdl_utils/Renderer.h"
#include "sdl_utils/MonitorWindow.h"
#include "sdl_utils/containers/ImageContainer.h"
#include "sdl_utils/containers/TextContainer.h"

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

    MonitorWindow _window;
    InputEvent _event;
    Renderer _renderer;
    ImageContainer _imgContainer;
    TextContainer _textContainer;
    Game _game;
};

#endif // !ENGINE_H
