#ifndef IMAGECONTAINER_H
#define IMAGECONTAINER_H

// C system includes

// C++ system includes
#include <cstdint>
#include <unordered_map>

// Third-party includes

// Own includes
#include "sdl_utils/config/ImageContainerCfg.h"
#include "utils/drawing/Rectangle.h"

//Forward declarations
struct SDL_Texture;

using Frames = std::vector<Rectangle>;

class ImageContainer {
public:
    SDL_Texture* getImageTexture(int32_t rsrcId) const;

    const Frames& getImageFrame(int32_t rsrcId) const;

protected:
    int32_t init(const ImageContainerConfig& imageCfg);
    
    void deinit();

private:
    int32_t loadSingleResource(const ImageConfig& resourceCfg, int32_t resourceId);

    std::unordered_map<int32_t, SDL_Texture*> _textures;
    std::unordered_map<int32_t, Frames> _textureFrames;
};

#endif // !IMAGECONTAINER_H
