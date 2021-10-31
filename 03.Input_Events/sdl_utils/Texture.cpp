// Corresponding headers
#include "Texture.h"

// C system includes

// C++ system includes
#include <cstdlib>
#include <iostream>

// Third-party includes
#include <SDL_surface.h>
#include <SDL_image.h>

// Own includes

int32_t Texture::createSurfaceFromFile(const std::string& filePath, SDL_Surface*& outSurface) {
    outSurface = IMG_Load(filePath.c_str());
    
    if (outSurface == nullptr) {
        std::cerr << "IMG_Load() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void Texture::freeSurface(SDL_Surface*& outSurface) {
    if (outSurface) {
        SDL_FreeSurface(outSurface);
        outSurface = nullptr;
    }
}
