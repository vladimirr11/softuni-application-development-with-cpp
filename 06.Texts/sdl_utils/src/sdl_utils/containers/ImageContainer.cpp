// Corresponding header
#include "sdl_utils/containers/ImageContainer.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/Texture.h"
// TODO remove
#include "utils/drawing/DrawParams.h"

int32_t ImageContainer::init(const ImageContainerConfig& cfg) {
    for (const auto& pair : cfg.imageConfigs) {
        const int32_t resId = pair.first;
        const auto& elem = pair.second;

        if (EXIT_SUCCESS != loadSingleResource(elem, resId)) {
            std::cerr << "In ImageContainer::init() loadSingleResource() failed for file: " << elem.location << std::endl;
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
    
void ImageContainer::deinit() {
    for (auto& pair : _textures) {
        Texture::freeTexture(pair.second);
    }
}

SDL_Texture* ImageContainer::getImageTexture(int32_t rsrcId) const {
    auto it = _textures.find(rsrcId);
    if (it == _textures.end()) {
        std::cerr << "Invalid rsrcId in ImageContainer::getImageTexture() " << rsrcId << "requested." << std::endl;
        return nullptr;
    }

    return it->second;
}

Rectangle ImageContainer::getImageFrame(int32_t rsrcId) const {
    auto it = _textureFrames.find(rsrcId);
    if (it == _textureFrames.end()) {
        std::cerr << "Invalid rsrcId in ImageContainer::getImageFrame() " << rsrcId << "requested."
                  << "Returning ZERO rectangle." << std::endl;
        return Rectangle::ZERO;
    }

    return it->second;
}

int32_t ImageContainer::loadSingleResource(const ImageConfig& resourceCfg, int32_t resourceId) {
    SDL_Texture* texture = nullptr;

    if (EXIT_SUCCESS != Texture::createTextureFromFile(resourceCfg.location, texture)) {
        std::cerr << "Texture::createTextureFromFile failed for file: " << resourceCfg.location << std::endl;
        return EXIT_FAILURE;
    }

    // TODO remove me 
    // temporary enable alpha blending for all existing textures
    if (EXIT_SUCCESS != Texture::setBlendModeTexture(texture, BlendMode::BLEND)) {
        std::cerr << "Texture::setBlendModeTexture() failed for file: " << resourceCfg.location << std::endl;
        return EXIT_FAILURE;
    }

    _textures[resourceId] = texture;

    Rectangle& rect = _textureFrames[resourceId];

    rect.x = 0;
    rect.y = 0;
    rect.w = resourceCfg.width;
    rect.h = resourceCfg.height;

    return EXIT_SUCCESS;
}
