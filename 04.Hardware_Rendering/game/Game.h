#ifndef GAME_H
#define GAME_H

// C system includes

// C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "game/config/GameConfig.h"

// Forward declarations
struct InputEvent;
struct SDL_Texture;

class Game {
public:
    int32_t init(const GameConfig& gameCfg);
    void deinit();
    void draw(std::vector<SDL_Texture*>& images);
    void handleEvent(const InputEvent& event);

private:
    int32_t loadResources(const std::unordered_map<GameImages, std::string>& gameCfgMap);

    SDL_Texture* _currChosenImage = nullptr;
    SDL_Texture* _imageSurfaces[COUNT] {};
};

#endif // !GAME_H
