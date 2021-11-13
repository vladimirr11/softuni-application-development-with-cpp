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
#include "includes/game/proxies/GameProxy.h"
#include "includes/game/buttons/WheelButton.h"

#include "manager_utils/drawing/Image.h"
#include "manager_utils/drawing/Text.h"

// Forward declarations
struct InputEvent;

class Game : public GameProxy {
public:
    int32_t init(const GameConfig& gameCfg);

    void deinit();

    void draw();

    void handleEvent(const InputEvent& event);

private:
    void onButtonPressed(int32_t buttonId) final;

    enum ButtonIndxs {
        WHEEL_START_BUTTON_IDX,
        WHEEL_STOP_BUTTON_IDX,
        WHEEL_BUTTONS_COUNT
    };

    Hero _hero;
    Wheel _wheel;
    WheelButton _wheelButtons[WHEEL_BUTTONS_COUNT];
};

#endif // !GAME_H
