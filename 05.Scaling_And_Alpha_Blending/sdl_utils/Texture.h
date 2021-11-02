#ifndef TEXTURE_H
#define TEXTURE_H

// C system includes

// C++ system includes
#include <cstdint>
#include <string>

// Third-party includes

// Own includes
#include "utils/drawing/DrawParams.h"

// Forward declarations
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;

class Texture {
public:
    Texture() = delete;
    ~Texture();

    static int32_t createSurfaceFromFile(const std::string& filePath, SDL_Surface*& outSusrface);

    static int32_t createTextureFromFile(const std::string& filePath, SDL_Texture*& outTexture);

    static int32_t createTextureFromSurface(SDL_Surface*& surface, SDL_Texture*& outTexture);

    static void freeSurface(SDL_Surface*& outSurface);

    static void freeTexture(SDL_Texture*& outTexture);

    static void setRenderer(SDL_Renderer* renderer);

    static int32_t setBlendModeTexture(SDL_Texture* texture, BlendMode blendMode);

    static int32_t setAlphaTexture(SDL_Texture* texture, int32_t alpha);

private:
};

#endif // !TEXTURE_H
