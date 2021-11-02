#ifndef SDLLOADER_H
#define SDLLOADER_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations

class SDLLoader {
public:
    SDLLoader() = delete;
    ~SDLLoader() = default;

    static int32_t init();

    static void deinit();

};

#endif // !SDLLOADER_H
