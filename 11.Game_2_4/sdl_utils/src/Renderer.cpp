// Corresponding header
#include "sdl_utils/Renderer.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_render.h>
#include <SDL_hints.h>

// Own includes
#include "sdl_utils/Texture.h"

int32_t Renderer::init(SDL_Window* window) {
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        std::cerr << "Warning: Linear texture filtering not enabled! "
                     "SDL_SetHint() failed. SDL Error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    constexpr auto driverId = -1;
    _sdlRenderer = SDL_CreateRenderer(window, driverId, SDL_RENDERER_ACCELERATED);
    if (_sdlRenderer == nullptr) {
        std::cerr << "SDL_CreateRenderer() failed in Renderer::init()! " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    if (SDL_SetRenderDrawColor(_sdlRenderer, 0, 0, 255, SDL_ALPHA_OPAQUE) != EXIT_SUCCESS) {
        std::cerr << "SDL_SetRenderDrawColor() failed in Renderer::init()! " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    Texture::setRenderer(_sdlRenderer);

    return EXIT_SUCCESS;
}

void Renderer::deinit() {
    if (_sdlRenderer) {
        SDL_DestroyRenderer(_sdlRenderer);
        _sdlRenderer = nullptr;
    }
}

void Renderer::clearScreen() {
    if (SDL_RenderClear(_sdlRenderer) != EXIT_SUCCESS) {
        std::cerr << "SDL_RenderClear() failed in Renderer::clearScreen()!" << SDL_GetError() << std::endl;
    }
}

void Renderer::renderTexture(SDL_Texture* texture, const DrawParams& drawParams) {
    if (drawParams.widgetType == WidgetType::IMAGE) {
        drawImage(drawParams, texture);
    } else if (drawParams.widgetType == WidgetType::TEXT) {
        drawText(drawParams, texture);
    } else {
        std::cerr << "Error, recieved unsupported WidgetType: " << static_cast<int32_t>(drawParams.widgetType) 
                  << " for resourceId - " << drawParams.rsrcId << std::endl; 
    }
}

void Renderer::finishFrame() {
    SDL_RenderPresent(_sdlRenderer);
}

void Renderer::setWidgetBlendMode(SDL_Texture* texture, BlendMode blendMode) {
    // enable alpha blending for all existing textures
    if (Texture::setBlendModeTexture(texture, blendMode) != EXIT_SUCCESS) {
        std::cerr << "Texture::setBlendModeTexture() failed in Renderer::setWidgetBlendMode()!" << std::endl;
    }
}

void Renderer::setWidgetOpacity(SDL_Texture* texture, int32_t opacity) {
    if (Texture::setAlphaTexture(texture, opacity) != EXIT_SUCCESS) {
        std::cerr << "Texture::setAlphaTexture() failed in Renderer::setWidgetOpacity()!" << std::endl;
    }
}

void Renderer::drawImage(const DrawParams& drawParams, SDL_Texture* texture) {  
    if (drawParams.opacity == FULL_OPACITY) {
        drawTextureInternal(drawParams, texture);
    } else {
        if (Texture::setAlphaTexture(texture, drawParams.opacity) != EXIT_SUCCESS) {
            std::cerr << "Texture::setAlphaTexture() failed in Renderer::drawImage() for resourceId: " 
                      << drawParams.rsrcId << std::endl;
        }

        drawTextureInternal(drawParams, texture);

        if (Texture::setAlphaTexture(texture, FULL_OPACITY) != EXIT_SUCCESS) {
            std::cerr << "Texture::setAlphaTexture() failed in Renderer::drawImage() for resourceId: " 
                      << drawParams.rsrcId << std::endl;
        }
    }
}

void Renderer::drawText(const DrawParams& drawParams, SDL_Texture* texture) {
    drawTextureInternal(drawParams, texture);
}

void Renderer::drawTextureInternal(const DrawParams& drawParams, SDL_Texture* texture) {
    const SDL_Rect destRect = { .x = drawParams.pos.x, .y = drawParams.pos.y, .w = drawParams.width, .h = drawParams.height};

    const SDL_Rect* sourceRect = reinterpret_cast<const SDL_Rect*>(&drawParams.frameRect);

    const SDL_Point* center = reinterpret_cast<const SDL_Point*>(&drawParams.rotationCenter);

    const int32_t errCode = SDL_RenderCopyEx(_sdlRenderer, 
                                             texture, 
                                             sourceRect, 
                                             &destRect, 
                                             drawParams.rotationAngle, 
                                             center, 
                                             static_cast<SDL_RendererFlip>(drawParams.widgetFlip));

    if (errCode != EXIT_SUCCESS) {
        std::cerr << "SDL_RenderCopy() failed in Renderer::drawTextureInternal() for resourceId. " 
                  << drawParams.rsrcId << "Reason: " << SDL_GetError() << std::endl;
    }
}
