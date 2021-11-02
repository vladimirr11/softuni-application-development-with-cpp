#ifndef TIME_H
#define TIME_H

// C system includes

// C++ system includes
#include <chrono>

// Third-party includes

// Own includes

// Forward declarations

class Time {
public:
    Time& getElapsed();
    
    int64_t toSeconds() const;
    int64_t toMilliseconds() const;
    int64_t toMicroseconds() const;
    int64_t toNanoseconds() const;

private:
    std::chrono::time_point<std::chrono::steady_clock> _now = std::chrono::steady_clock::now();
    std::chrono::time_point<std::chrono::steady_clock> _elapsedLastCall;

};

#endif // !TIME_H
