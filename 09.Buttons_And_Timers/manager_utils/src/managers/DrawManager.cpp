// Corresponding header
#include "manager_utils/managers/DrawManager.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "manager_utils/managers/config/DrawManagerCfg.h"
#include "manager_utils/managers/ResourceManager.h"
#include "utils/drawing/DrawParams.h"

DrawManager* gDrawMgr = nullptr;

int32_t DrawManager::init(const DrawManagerCfg& drawMgrCfg) {
    if (_window.init(drawMgrCfg.windowConfig) != EXIT_SUCCESS) {
        std::cerr << "MinitorWindow::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (_renderer.init(_window.getWindow()) != EXIT_SUCCESS) {
        std::cerr << "Renderer::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void DrawManager::deinit() {
    _renderer.deinit();
    _window.deinit();
}

void DrawManager::process() {

}

void DrawManager::clearScreen() {
    _renderer.clearScreen();
}

void DrawManager::finishFrame() {
    _renderer.finishFrame();
}

void DrawManager::addDrawCmd(const DrawParams& drawParams) {
    SDL_Texture* texture = getTextureInternal(drawParams);
    _renderer.renderTexture(texture, drawParams);
}

void DrawManager::setWidgetBlendMode(const DrawParams& drawParams, BlendMode blendMode) {
    SDL_Texture* texture = getTextureInternal(drawParams);
    _renderer.setWidgetBlendMode(texture, blendMode);
}

void DrawManager::setWidgetOpacity(const DrawParams& drawParams, int32_t opacity) {
    if (drawParams.widgetType == WidgetType::IMAGE) {
        return;
    }
    
    SDL_Texture* texture = getTextureInternal(drawParams);
    _renderer.setWidgetOpacity(texture, opacity);
}   

SDL_Texture* DrawManager::getTextureInternal(const DrawParams& drawParams) const {
    if (drawParams.widgetType == WidgetType::TEXT) {
        return gResourceMgr->getTextTexture(drawParams.rsrcId);
    } else if (drawParams.widgetType == WidgetType::IMAGE) {
        return gResourceMgr->getImageTexture(drawParams.rsrcId);
    } else {
        std::cerr << "Error, recieved unsupported WidgetType in Engine::drawFrame(): " 
                  << static_cast<int32_t>(drawParams.widgetType) 
                  << " for resourceId - " << drawParams.rsrcId << std::endl; 
    }

    return nullptr;
}   
