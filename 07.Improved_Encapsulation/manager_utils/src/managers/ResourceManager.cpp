// Corresponding header
#include "manager_utils/managers/ResourceManager.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "manager_utils/managers/config/ResourceManagerCfg.h"

ResourceManager* gResourceMgr = nullptr;

int32_t ResourceManager::init(const ResourceManagerCfg& darwMgrCfg) {
    if (ImageContainer::init(darwMgrCfg.imageContainerCfg) != EXIT_SUCCESS) {
        std::cerr << "ImageContainer::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (TextContainer::init(darwMgrCfg.textContainerCfg) != EXIT_SUCCESS) {
        std::cerr << "TextContainer::init() failed." << std::endl;
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