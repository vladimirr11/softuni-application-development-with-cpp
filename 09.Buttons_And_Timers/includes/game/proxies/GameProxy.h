#ifndef GAMEPROXY_H
#define GAMEPROXY_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

class GameProxy {
public:
    virtual ~GameProxy() = default;
    virtual void onButtonPressed(int32_t buttonId) = 0;
};

#endif // !GAMEPROXY_H
