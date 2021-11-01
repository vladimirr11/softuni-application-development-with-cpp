// Corresponding header
#include "Renderer.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_render.h>

// Own includes
#include "sdl_utils/Texture.h"

int32_t Renderer::init(SDL_Window* window) {
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

void Renderer::renderTexture(SDL_Texture* texture) {
    SDL_RenderCopy(_sdlRenderer, texture, nullptr, nullptr);
}
