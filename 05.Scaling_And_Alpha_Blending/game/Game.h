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

class Game {
public:
    int32_t init(const GameConfig& gameCfg, const ImageContainer* imageContainerInterface);
    void deinit();
    void draw(std::vector<DrawParams>& images);
    void handleEvent(const InputEvent& event);

private:
    // TODO remove!!!
    const ImageContainer* _imgContainer = nullptr;

    DrawParams pressKeysImg;
    DrawParams pressKeysImg2;
    DrawParams layer2Img;
};

#endif // !GAME_H
