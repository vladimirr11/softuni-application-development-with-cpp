#ifndef GAME_H
#define GAME_H

// C system includes

// C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "game/config/GameConfig.h"
#include "utils/drawing/DrawParams.h"

// Forward declarations
struct InputEvent;
struct ImageContainer;
struct TextContainer;

class Game {
public:
    int32_t init(const GameConfig& gameCfg, const ImageContainer* imageContainerInterface, TextContainer* textContainerInterface);

    void deinit();

    void draw(std::vector<DrawParams>& images);

    void handleEvent(const InputEvent& event);

private:
    DrawParams pressKeysImg;
    DrawParams layer2Img;

    DrawParams helloSDLText;
    DrawParams pressText;
    DrawParams hideText;

    bool isPressTextHidden = false;

    // TODO remove these!!!
    const ImageContainer* _imgContainer = nullptr;
    TextContainer* _textContainer = nullptr;
};

#endif // !GAME_H
