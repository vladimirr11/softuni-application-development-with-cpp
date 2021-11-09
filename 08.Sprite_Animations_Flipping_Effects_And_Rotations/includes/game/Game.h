#ifndef GAME_H
#define GAME_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "includes/game/config/GameConfig.h"
#include "includes/game/entities/Hero.h"
#include "includes/game/entities/Wheel.h"

#include "manager_utils/drawing/Image.h"
#include "manager_utils/drawing/Text.h"

// Forward declarations
struct InputEvent;

class Game {
public:
    int32_t init(const GameConfig& gameCfg);

    void deinit();

    void draw();

    void handleEvent(const InputEvent& event);

private:
    void setMousePosText(const Point& mousePos);

    Hero _hero;
    Wheel _wheel;
    Text _mousePosText;
};

#endif // !GAME_H
