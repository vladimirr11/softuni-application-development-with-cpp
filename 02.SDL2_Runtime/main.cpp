// C system includes

// C++ system includes
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

#define SDL_MAIN_HANDLED

// Third-party includes
#include <SDL.h>

// Own includes
#include "sdl_utils/SDLLoader.h"
#include "sdl_utils/MonitorWindow.h"
#include "sdl_utils/Texture.h"

static void draw(MonitorWindow& window, SDL_Surface* image) {
    SDL_Surface* screenSurfice = window.getWindowSurfice();
    SDL_BlitSurface(image, nullptr, screenSurfice, nullptr);
    
    window.updateWindowSurfice();

    SDL_Delay(3000);
}

static int32_t loadResources(SDL_Surface*& outImage) {
    const std::string filePath = "../resources/hello.png";
    if (EXIT_SUCCESS != Texture::createSurfaceFromFile(filePath, outImage)) {
        std::cerr << "createSurfaceFrom file failed for file: " << filePath << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static int32_t init(MonitorWindow& window, SDL_Surface*& outImage) {
    MonitorWindowCfg cfg;

    // SDL window show
    cfg.windowName = "SDL2_Runtime";

    cfg.windowWidth = 640;
    cfg.windowHeight = 480;

    cfg.windowFlags = WINDOW_FULLSCREEN_MODE;

    if (window.init(cfg) != EXIT_SUCCESS) {
        std::cerr << "Minitor::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (loadResources(outImage) != EXIT_SUCCESS) {
        std::cerr << "loadResources failed." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static void deinit(MonitorWindow& window, SDL_Surface*& outImage) {
    Texture::freeSurface(outImage);
    window.deinit();
}

static int32_t runApplication() {
    MonitorWindow window;
    SDL_Surface* image = nullptr;

    if (init(window, image) != EXIT_SUCCESS) {
        std::cerr << "init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    draw(window, image);

    deinit(window, image);

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
