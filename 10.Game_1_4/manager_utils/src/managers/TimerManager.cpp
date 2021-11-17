// Corresponding header
#include "manager_utils/managers/TimerManager.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "manager_utils/timer/TimerClient.h"

TimerManager* gTimerManager = nullptr;

int32_t TimerManager::init() {
    _elapsedTime.getElapsed();

    return EXIT_SUCCESS;
}

void TimerManager::process() {
    const int64_t msElapsed = _elapsedTime.getElapsed().toMilliseconds();

    for (auto it = _timerMap.begin(); it != _timerMap.end(); ++it) {
        it->second.remainingTime -= msElapsed;
        if (0 > it->second.remainingTime) {
            onTimerTimeout(it->first, it->second);
        }
    }

    removeTimersInternal();
}

void TimerManager::deinit() {

}

void TimerManager::startTimer(const int32_t timerId, const TimerData& tData) {
    if (isActiveTimerId(timerId)) {
        std::cerr << "Error, trying to start already existing timer - " << timerId << std::endl;
        return;
    }

    _timerMap.emplace(timerId, tData);
}

void TimerManager::stopTimer(int32_t timerId) {
    if (!isActiveTimerId(timerId)) {
        std::cerr << "Error, trying to stop already stopped timer - " << timerId << std::endl;
        return;
    }

    _removeTimerSet.insert(timerId);
}

bool TimerManager::isActiveTimerId(int32_t timerId) const {
    return (_removeTimerSet.end() == _removeTimerSet.find(timerId))
            && (_timerMap.end() != _timerMap.find(timerId));
}

void TimerManager::onInitEnd() {
    _elapsedTime.getElapsed();
}

void TimerManager::removeTimersInternal() {
    for (const int32_t timerId : _removeTimerSet) {
        auto mapIt = _timerMap.find(timerId);
        if (mapIt != _timerMap.end()) {
            _timerMap.erase(mapIt);
        }
    }
    
    _removeTimerSet.clear();
}

void TimerManager::onTimerTimeout(int32_t timerId, TimerData& tData) {
    if (tData.timerType == TimerType::ONESHOT) {
        _removeTimerSet.insert(timerId);
    }

    tData.timerClient->onTimeout(timerId);
    tData.remainingTime += tData.interval;
}
