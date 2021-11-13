#ifndef TIMERMANAGER_H
#define TIMERMANAGER_H

// C system includes

// C++ system includes
#include <cstdint>
#include <map>
#include <set>

// Third-party includes

// Own includes
#include "manager_utils/managers/ManagerBase.h"
#include "manager_utils/timer/TimerData.h"
#include "utils/time/Time.h"

// Forward declarations

class TimerManager: public ManagerBase {
public:
    int32_t init();
    
    void deinit() final;

    void process() final;

    void startTimer(const int32_t timerId, const TimerData& tData);

    void stopTimer(int32_t timerId);

    // void detachTimerClient(int32_t timerId);

    bool isActiveTimerId(int32_t timerId) const;

    void onInitEnd();

private:
    void removeTimersInternal();

    void onTimerTimeout(int32_t timerId, TimerData& tData);

    Time _elapsedTime;
    std::map<int32_t, TimerData> _timerMap;
    std::set<int32_t> _removeTimerSet;
};

extern TimerManager* gTimerManager;

#endif // !TIMERMANAGER_H
