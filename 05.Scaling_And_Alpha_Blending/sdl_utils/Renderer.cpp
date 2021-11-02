// Corresponding header
#include "Renderer.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_render.h>
#include <SDL_hints.h>

// Own includes
#include "sdl_utils/Texture.h"
#include "utils/drawing/DrawParams.h"

int32_t Renderer::init(SDL_Window* window) {
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        std::cerr << "Warning: Linear texture filtering not enabled! "
                     "SDL_SetHint() failed. SDL Error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    constexpr auto driverId = -1;
    _sdlRenderer = SDL_CreateRenderer(window, driverId, SDL_RENDERER_ACCELERATED);
    if (_sdlRenderer == nullptr) {
        std::cerr << "SDL_CreateRenderer() failed." << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    if (EXIT_SUCCESS != SDL_SetRenderDrawColor(_sdlRenderer, 0, 0, 255, SDL_ALPHA_OPAQUE)) {
        std::cerr << "SDL_SetRenderDrawColor() failed." << SDL_GetError() << std::endl;
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
    if (EXIT_SUCCESS != SDL_RenderClear(_sdlRenderer)) {
        std::cerr << "SDL_RenderClear() failed." << SDL_GetError() << std::endl;
    }
}

void Renderer::finishFrame() {
    SDL_RenderPresent(_sdlRenderer);
}

void Renderer::renderTexture(SDL_Texture* texture, const DrawParams& drawParams) {
    const SDL_Rect destRect = { .x = drawParams.pos.x, .y = drawParams.pos.y, .w = drawParams.width, .h = drawParams.height};

    int32_t errCode = EXIT_SUCCESS;
    if (FULL_OPACITY == drawParams.opacity) {
        errCode = SDL_RenderCopy(_sdlRenderer, texture, nullptr, &destRect);
    } else {
        if (Texture::setAlphaTexture(texture, drawParams.opacity) != EXIT_SUCCESS) {
            std::cerr << "Texture::setAlphaTexture() failed for resourceId: " 
                      << drawParams.rsrcId << std::endl;
        }

        errCode = SDL_RenderCopy(_sdlRenderer, texture, nullptr, &destRect);

        if (Texture::setAlphaTexture(texture, FULL_OPACITY) != EXIT_SUCCESS) {
            std::cerr << "Texture::setAlphaTexture() failed for resourceId: " 
                      << drawParams.rsrcId << std::endl;
        }
    }
    
    if (errCode != EXIT_SUCCESS) {
        std::cerr << "SDL_RenderCopy() failed for resourceId. " 
                  << drawParams.rsrcId << "Reason: " << SDL_GetError() << std::endl;
    }
}
