// Corresponding headers
#include "Texture.h"

// C system includes

// C++ system includes
#include <cstdlib>
#include <iostream>

// Third-party includes
#include <SDL_surface.h>
#include <SDL_image.h>
#include <SDL_render.h>

// Own includes

static SDL_Renderer* gRendererPtr = nullptr;

int32_t Texture::createSurfaceFromFile(const std::string& filePath, SDL_Surface*& outSurfice) {
    outSurfice = IMG_Load(filePath.c_str());
    
    if (outSurfice == nullptr) {
        std::cerr << "IMG_Load() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int32_t Texture::createTextureFromFile(const std::string& filePath, SDL_Texture*& outSurface) {
    SDL_Surface* tempSurface = nullptr;
    if (createSurfaceFromFile(filePath, tempSurface) != EXIT_SUCCESS) {
        std::cerr << "Texture::createTextureFromFile() failed for filePath: " << filePath << std::endl;
        return EXIT_FAILURE;
    }

    if (createTextureFromSurface(tempSurface, outSurface) != EXIT_SUCCESS) {
        std::cerr << "Texture::createTextureFromFile() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int32_t Texture::createTextureFromSurface(SDL_Surface*& surface, SDL_Texture*& outTexture) {
    outTexture = SDL_CreateTextureFromSurface(gRendererPtr, surface);

    if (outTexture == nullptr) {
        std::cerr << "Texture::createTextureFromSurface() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    freeSurface(surface);

    return EXIT_SUCCESS;
}

void Texture::freeSurface(SDL_Surface*& outSurface) {
    if (outSurface) {
        SDL_FreeSurface(outSurface);
        outSurface = nullptr;
    }
}

void Texture::freeTexture(SDL_Texture*& outTexture) {
    if (outTexture) {
        SDL_DestroyTexture(outTexture);
        outTexture = nullptr;
    }
}

void Texture::setRenderer(SDL_Renderer* renderer) {
    gRendererPtr = renderer;
}
