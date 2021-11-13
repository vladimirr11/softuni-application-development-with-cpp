#ifndef TIMERCLIENT_H
#define TIMERCLIENT_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "manager_utils/timer/TimerData.h"

// Forward declarations

class TimerClient {
public:
    virtual ~TimerClient() = default;
    
    virtual void onTimeout(int32_t timerId) = 0;

    void startTimer(int64_t interval, int32_t timerId, TimerType timerType);

    void stopTimer(int32_t timerId);

    bool isActiveTimerId(int32_t timerId) const;
};

#endif // !TIMERCLIENT_H
