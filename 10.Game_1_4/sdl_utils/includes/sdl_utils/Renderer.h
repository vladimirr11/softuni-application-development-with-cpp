#ifndef RENDERER_H
#define RENDERER_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/drawing/DrawParams.h"

//Forward declarations
struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Window;

class Renderer {
public:
    Renderer() = default;

    Renderer(const Renderer& other) = delete;
    Renderer(Renderer&& other) = delete;

    Renderer& operator=(const Renderer& other) = delete;
    Renderer& operator=(Renderer&& other) = delete;

    int32_t init(SDL_Window* window);
    void deinit();
    void clearScreen();
    void renderTexture(SDL_Texture* texture, const DrawParams& drawParams);
    void finishFrame();

    void setWidgetBlendMode(SDL_Texture* texture, BlendMode blendMode);
    void setWidgetOpacity(SDL_Texture* texture, int32_t opacity);

private:
    void drawImage(const DrawParams& drawParams, SDL_Texture* texture);
    void drawText(const DrawParams& drawParams, SDL_Texture* texture);

    void drawTextureInternal(const DrawParams& drawParams, SDL_Texture* texture);

    SDL_Renderer* _sdlRenderer = nullptr;
};


#endif // !RENDERER_H
