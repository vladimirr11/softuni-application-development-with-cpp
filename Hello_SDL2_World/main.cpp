// C++ system includes
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

#define SDL_MAIN_HANDLED

// Third-party includes
#include <SDL.h>

SDL_Window* gWindow = nullptr;
SDL_Surface* globalScreenSurfice = nullptr;
SDL_Surface* globalImage = nullptr;

static void draw() {
    SDL_BlitSurface(globalImage, nullptr, globalScreenSurfice, nullptr);
    if (EXIT_SUCCESS != SDL_UpdateWindowSurface(gWindow)) {
        std::cerr << "SDL_UpdateWindowSurface() failed. Reason: " << SDL_GetError() << std::endl;
    }

    SDL_Delay(3000);
}

static int32_t loadResources() {
    const std::string filePath = "../resources/hello.bmp";
    globalImage = SDL_LoadBMP(filePath.c_str());
    
    if (globalImage == nullptr) {
        std::cerr << "SDL_LoadBMP() failed. Reason: " << SDL_GetError() << std::endl;
    }

    return EXIT_SUCCESS;
}

static int32_t init() {
    if (SDL_Init(SDL_INIT_VIDEO) != EXIT_SUCCESS) {
        std::cerr << "SDL_Init() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    // SDL window show
    const std::string windowName = "Hello, SDL2 World!";

    const int32_t windowX = SDL_WINDOWPOS_UNDEFINED;
    const int32_t windowY = SDL_WINDOWPOS_UNDEFINED;
    const int32_t windowWidth = 640;
    const int32_t windowHeight = 480;

    gWindow = SDL_CreateWindow(windowName.c_str(), 
                windowX, windowY, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    
    if (gWindow == nullptr) {
        std::cerr << "SDL_CreateWindow() failed. Reason: " << SDL_GetError() << std::endl;
    }

    globalScreenSurfice = SDL_GetWindowSurface(gWindow);

    if (globalScreenSurfice == nullptr) {
        std::cerr << "SDL_GetWindowSurface() failed. Reason: " << SDL_GetError() << std::endl;
    }

    if (loadResources() != EXIT_SUCCESS) {
        std::cerr << "loadResources failed." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static void deinit() {
    SDL_FreeSurface(globalImage);

    if (gWindow != nullptr) {
        SDL_DestroyWindow(gWindow);
        gWindow = nullptr;
    }

    SDL_Quit();
}

int32_t main([[maybe_unused]]int32_t argc, [[maybe_unused]]char* argv[]) {
    if (init() != EXIT_SUCCESS) {
        std::cerr << "init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    draw();

    deinit();

    std::cout << "It works!" << std::endl;

    return EXIT_SUCCESS;
}
