#ifndef WHEEL_H
#define WHEEL_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "manager_utils/drawing/Image.h"
#include "manager_utils/timer/TimerClient.h"

//Forward declarations
struct InputEvent;

class Wheel : public TimerClient {
public:
    ~Wheel();

    int32_t init(int32_t wheelResourceId, int32_t rotateWheelTimerId, int32_t scaleTimerId);

    void draw();

    void handleEvent(const InputEvent& event);

    void startAnimation();
    void stopAnimation();

private:
    void onTimeout(int32_t timerId) final;

    void processWheelAnimation();

    void processScaleAnimation();

    int32_t _rotationWheelTimerId = -1;

    int32_t _scaleTimerId = -1;
    int32_t _scaleSteps = 50;

    bool _isAnimationActive = false;
    bool _isShrinked = true;
    
    Image _wheelImage;
};

#endif // !WHEEL_H
