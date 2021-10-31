#ifndef TEXTURE_H
#define TEXTURE_H

// C system includes

// C++ system includes
#include <cstdint>
#include <string>
#include <string>

// Third-party includes

// Own includes

// Forward declarations
struct SDL_Surface;

class Texture {
public:
    Texture() = delete;
    ~Texture();

    static int32_t createSurfaceFromFile(const std::string& filePath, SDL_Surface*& outSusrface);

    static void freeSurface(SDL_Surface*& outSurface);

private:
};

#endif // !TEXTURE_H
