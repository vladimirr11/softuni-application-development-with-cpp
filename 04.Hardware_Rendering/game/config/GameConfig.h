#ifndef GAMECONFIG_H
#define GAMECONFIG_H

// C system includes

// C++ system includes
#include <cstdint>
#include <unordered_map>
#include <string>

// Third-party includes

// Own includes

// Forward declarations

enum GameImages {
    UP, DOWN, LEFT, RIGHT, PRESS_KEYS, LAYER_2, COUNT
};

struct GameConfig {
    std::unordered_map<GameImages, std::string> imgLoadPaths;
};

#endif // !GAMECONFIG_H
