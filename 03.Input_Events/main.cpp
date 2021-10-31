// C system includes

// C++ system includes
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

#define SDL_MAIN_HANDLED

// Third-party includes

// Own includes
#include "sdl_utils/SDLLoader.h"
#include "engine/Engine.h"

static int32_t runApplication() {
    Engine engine;

    if (engine.init() != EXIT_SUCCESS) {
        std::cerr << "Engine init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    engine.start();

    engine.deinit();

    return EXIT_SUCCESS;
}

int32_t main([[maybe_unused]]int32_t argc, [[maybe_unused]]char* argv[]) {
    if (SDLLoader::init() != EXIT_SUCCESS) {
        std::cerr << "SDLLoader::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (runApplication() != EXIT_SUCCESS) {
        std::cerr << "runApplication() failed." << std::endl;
        return EXIT_FAILURE;
    }

    SDLLoader::deinit();

    std::cout << "It works!" << std::endl;

    return EXIT_SUCCESS;
}
