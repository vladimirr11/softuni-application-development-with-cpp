#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "manager_utils/managers/ManagerBase.h"
#include "sdl_utils/Renderer.h"
#include "sdl_utils/MonitorWindow.h"

// Forward declarations
struct DrawManagerConfig;
struct SDL_Texture;

class DrawManager: public ManagerBase {
public:
    DrawManager() = default;

    DrawManager(const DrawManager& other) = delete;
    DrawManager(DrawManager&& other) = delete;

    DrawManager& operator=(const DrawManager& other) = delete;
    DrawManager& operator=(DrawManager&& other) = delete;

    int32_t init(const DrawManagerConfig& darwMgrCfg);

    void deinit() final;
    void process() final;

    void clearScreen();
    void finishFrame();
    void addDrawCmd(const DrawParams& drawParams);

    void setWidgetBlendMode(const DrawParams& drawParams, BlendMode blendMode);
    void setWidgetOpacity(const DrawParams& drawParams, int32_t opacity);

private:
    SDL_Texture* getTextureInternal(const DrawParams& drawParams) const;

    Renderer _renderer;
    MonitorWindow _window;

    // Hold maximum frame rate cap
    int64_t _maxFrames { 0 };
};

extern DrawManager* gDrawMgr;

#endif // !DRAWMANAGER_H
