// Corresponding header
#include "Game.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/InputEvent.h"
#include "utils/drawing/Color.h"

// TODO remove these!
#include "sdl_utils/containers/ImageContainer.h"
#include "sdl_utils/containers/TextContainer.h"

static int32_t gFontId;

int32_t Game::init(const GameConfig& gameCfg, const ImageContainer* imageContainerInterface, TextContainer* textContainerInterface) {
    if (imageContainerInterface == nullptr) {
        std::cerr << "nullptr provided for imageContainerInterface!" << std::endl;
        return EXIT_FAILURE;
    }

    _imgContainer = imageContainerInterface;

    gFontId = gameCfg.textFontId;

    if (textContainerInterface == nullptr) {
        std::cerr << "nullptr provided for textContainerInterface!" << std::endl;
        return EXIT_FAILURE;
    }

    _textContainer = textContainerInterface;

    layer2Img.rsrcId = gameCfg.layer2ResourceId;
    Rectangle rect = _imgContainer->getImageFrame(layer2Img.rsrcId);
    layer2Img.width = rect.w;
    layer2Img.height = rect.h;
    layer2Img.pos = Point::ZERO;
    layer2Img.widgetType = WidgetType::IMAGE;

    pressKeysImg.rsrcId = gameCfg.pressKeysResourceId;
    rect = _imgContainer->getImageFrame(pressKeysImg.rsrcId);
    pressKeysImg.width = rect.w;
    pressKeysImg.height = rect.h;
    pressKeysImg.pos = Point::ZERO;
    pressKeysImg.widgetType = WidgetType::IMAGE;

    _textContainer->createText("Hello, SDL2 world!", Colors::ORANGE, gameCfg.textFontId, 
                               helloSDLText.textId, helloSDLText.width, helloSDLText.height);
    helloSDLText.pos = Point::ZERO;
    helloSDLText.widgetType = WidgetType::TEXT;

    _textContainer->createText("Press M to Hide!", Colors::ORANGE, gameCfg.textFontId, 
                               pressText.textId, pressText.width, pressText.height);
    pressText.pos = Point::ZERO;
    pressText.pos.x += 100;
    pressText.pos.y += 100;
    pressText.widgetType = WidgetType::TEXT;

    _textContainer->createText("Press N to Show!", Colors::ORANGE, gameCfg.textFontId, 
                               hideText.textId, hideText.width, hideText.height);
    hideText.pos = Point::ZERO;                           
    hideText.pos.x += 200;
    hideText.pos.y += 200;
    hideText.widgetType = WidgetType::TEXT;

    return EXIT_SUCCESS;
}

void Game::deinit() {
    _textContainer->unloadText(helloSDLText.textId);
}

void Game::draw(std::vector<DrawParams>& images) {
    // images.push_back(pressKeysImg);
    // images.push_back(layer2Img);
    images.push_back(helloSDLText);
    if (isPressTextHidden) {
        images.push_back(hideText);
    } else {
        images.push_back(pressText);
    }
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
        pressKeysImg.opacity -= 10;
        break;
    case Keyboard::KEY_Y:
        pressKeysImg.opacity += 10;
        break;   

    case Keyboard::KEY_B:
        _textContainer->createText("How it is going?", Colors::ORANGE, gFontId, 
                               helloSDLText.textId, helloSDLText.width, helloSDLText.height);
        break;      
    
    case Keyboard::KEY_M:
        isPressTextHidden = true;
        break;
    case Keyboard::KEY_N:
        isPressTextHidden = false;
        break;

    default:
        break;
    }
}
