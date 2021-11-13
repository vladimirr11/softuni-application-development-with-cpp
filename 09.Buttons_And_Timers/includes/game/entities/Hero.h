#ifndef HERO_H
#define HERO_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "manager_utils/drawing/Image.h"
#include "manager_utils/timer/TimerClient.h"

// Forward declarations
struct InputEvent;

class Hero : TimerClient {
public:
    int32_t init(int32_t resourceId, int32_t timerId);

    void deinit();

    void draw();

    void handleEvent(const InputEvent& event);

    void startHeroAnimation();

private:
    void processHeroAnimation();

    void onTimeout(int32_t timerId) final;

    Image _heroImg;
    int32_t _heroTimerId = -1;
    int32_t _moveHeroRate = 50;
};

#endif // !HERO_H
