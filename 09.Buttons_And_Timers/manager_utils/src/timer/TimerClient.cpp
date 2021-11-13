// Corresponding header
#include "manager_utils/timer/TimerClient.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "manager_utils/managers/TimerManager.h"

void TimerClient::startTimer(int64_t interval, int32_t timerId, TimerType timerType) {
    constexpr int32_t minTimerInterval = 20;
    if (interval < minTimerInterval) {
        std::cerr << "Timer interval is lower than the minimum interval!" << std::endl;
        return;
    }

    const TimerData tData(interval, interval, timerType, this);
    gTimerManager->startTimer(timerId, tData);
}

void TimerClient::stopTimer(int32_t timerId) {
    gTimerManager->stopTimer(timerId);
}

bool TimerClient::isActiveTimerId(int32_t timerId) const {
    return gTimerManager->isActiveTimerId(timerId);
}
