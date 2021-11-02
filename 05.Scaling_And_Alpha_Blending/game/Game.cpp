// Corresponding header
#include "Game.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/InputEvent.h"
#include "sdl_utils/containers/ImageContainer.h"

int32_t Game::init(const GameConfig& gameCfg, const ImageContainer* imageContainerInterface) {
    if (imageContainerInterface == nullptr) {
        std::cerr << "nullptr provided for imageContainerInterface!" << std::endl;
        return EXIT_FAILURE;
    }

    _imgContainer = imageContainerInterface;

    layer2Img.rsrcId = gameCfg.layer2ResourceId;
    Rectangle rect = _imgContainer->getImageFrame(layer2Img.rsrcId);
    layer2Img.width = rect.w;
    layer2Img.height = rect.h;
    layer2Img.pos = Point::ZERO;

    pressKeysImg.rsrcId = gameCfg.pressKeysResourceId;
    rect = _imgContainer->getImageFrame(pressKeysImg.rsrcId);
    pressKeysImg.width = rect.w;
    pressKeysImg.height = rect.h;
    pressKeysImg.pos = Point::ZERO;

    pressKeysImg2 = pressKeysImg;
    pressKeysImg.pos.x += 200;

    return EXIT_SUCCESS;
}

void Game::deinit() {

}

void Game::draw(std::vector<DrawParams>& images) {
    images.push_back(pressKeysImg2);
    images.push_back(pressKeysImg);
    // images.push_back(layer2Img);
}

void Game::handleEvent(const InputEvent& event) {
    if (event.typeTouchEvent != TouchEvent::KEYBOARD_RELEASE) {
        return;
    }

    switch (event.key) {
    case Keyboard::KEY_UP:
        pressKeysImg.pos.y -= 10;
        break;
    case Keyboard::KEY_DOWN:
        pressKeysImg.pos.y += 10;
        break;
    case Keyboard::KEY_LEFT:
        pressKeysImg.pos.x -= 10;
        break;
    case Keyboard::KEY_RIGHT:
        pressKeysImg.pos.x += 10;
        break;
        
    case Keyboard::KEY_Q:
        pressKeysImg.width -= 10;
        break;
    case Keyboard::KEY_W:
        pressKeysImg.width += 10;
        break;
    case Keyboard::KEY_E:
        pressKeysImg.height -= 10;
        break;
    case Keyboard::KEY_R:
        pressKeysImg.height += 10;
        break;

    case Keyboard::KEY_T:
        pressKeysImg.opacity += 10;
        break;
    case Keyboard::KEY_Y:
        pressKeysImg.opacity -= 10;
        break;         

    default:
        break;
    }
}
