// Corresponding header
#include "manager_utils/managers/ResourceManager.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "manager_utils/managers/config/ResourceManagerCfg.h"

ResourceManager* gResourceManager = nullptr;

int32_t ResourceManager::init(const ResourceManagerConfig& resourceMgrCfg) {
    if (ImageContainer::init(resourceMgrCfg.imageContainerCfg) != EXIT_SUCCESS) {
        std::cerr << "ImageContainer::init() failed ResourceManager::init()!" << std::endl;
        return EXIT_FAILURE;
    }

    if (TextContainer::init(resourceMgrCfg.textContainerCfg) != EXIT_SUCCESS) {
        std::cerr << "TextContainer::init() failed ResourceManager::init()!" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void ResourceManager::deinit() {
    TextContainer::deinit();
    ImageContainer::deinit();
}

void ResourceManager::process() {

}
