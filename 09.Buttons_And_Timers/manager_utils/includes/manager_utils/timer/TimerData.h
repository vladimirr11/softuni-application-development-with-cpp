#ifndef TIMERDATA_H
#define TIMERDATA_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations
struct TimerClient;

enum class TimerType : uint8_t {
    ONESHOT, 
    PULSE
};

struct TimerData {
    TimerData(int64_t inputInterval, int64_t inputRemainingTime, TimerType inputTT, TimerClient* inputTC) : 
        interval(inputInterval), remainingTime(inputRemainingTime), timerType(inputTT), timerClient(inputTC) {}

    int64_t interval;
    int64_t remainingTime;
    TimerType timerType;

    TimerClient* timerClient = nullptr;
};

#endif // !TIMERDATA_H
