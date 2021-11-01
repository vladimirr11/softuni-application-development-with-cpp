// Corresponding header
#include "Game.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/Texture.h"
#include "sdl_utils/InputEvent.h"

int32_t Game::init(const GameConfig& gameCfg) {
    if (loadResources(gameCfg.imgLoadPaths) != EXIT_SUCCESS) {
        std::cerr << "Game::loadResources() failed." << std::endl;
        return EXIT_FAILURE;
    }

    _currChosenImage = _imageSurfaces[PRESS_KEYS];

    return EXIT_SUCCESS;
}

void Game::deinit() {
    for (int32_t i = 0; i < COUNT; i++) {
        Texture::freeTexture(_imageSurfaces[i]);
    }
}

void Game::draw(std::vector<SDL_Texture*>& images) {
    for (int32_t i = 0; i < 20; i++) {
        images.push_back(_currChosenImage);
    }
}

void Game::handleEvent(const InputEvent& event) {
    if (event.typeTouchEvent == TouchEvent::KEYBOARD_RELEASE) {
        _currChosenImage = _imageSurfaces[PRESS_KEYS];
        return;
    }

    if (event.typeTouchEvent != TouchEvent::KEYBOARD_PRESS) {
        return;
    }

    switch (event.key) {
    case Keyboard::KEY_UP:
        _currChosenImage = _imageSurfaces[UP];
        break;
    case Keyboard::KEY_DOWN:
        _currChosenImage = _imageSurfaces[DOWN];
        break;
    case Keyboard::KEY_LEFT:
        _currChosenImage = _imageSurfaces[LEFT];
        break;
    case Keyboard::KEY_RIGHT:
        _currChosenImage = _imageSurfaces[RIGHT];
        break;

    default:
        break;
    }
}

int32_t Game::loadResources(const std::unordered_map<GameImages, std::string>& gameCfgMap) {

    for (const auto& imgPathPair : gameCfgMap) {
        const auto imgId = imgPathPair.first;
        const auto& imgPath = imgPathPair.second;
        if (EXIT_SUCCESS != Texture::createTextureFromFile(imgPath, _imageSurfaces[imgId])) {
            std::cerr << "Texture::createTextureFromFile failed for file: " << imgPath << std::endl;
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
