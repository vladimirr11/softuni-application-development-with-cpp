#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

// C system includes

// C++ system includes

// Third-party includes

// Own includes
#include "manager_utils/managers/ManagerBase.h"
#include "sdl_utils/containers/ImageContainer.h"
#include "sdl_utils/containers/TextContainer.h"

// Forward declarations
struct ResourceManagerConfig;

class ResourceManager: public ManagerBase, 
                       public ImageContainer, 
                       public TextContainer {
public:
    ResourceManager() = default;

    ResourceManager(const ResourceManager& other) = delete;
    ResourceManager(ResourceManager&& other) = delete;

    ResourceManager& operator=(const ResourceManager& other) = delete;
    ResourceManager& operator=(ResourceManager&& other) = delete;

    
    int32_t init(const ResourceManagerConfig& darwMgrCfg);

    void deinit() final;
    void process() final;

private:
    ImageContainer _imgContainer;
    TextContainer _textContainer;
};

extern ResourceManager* gResourceMgr;

#endif // !RESOURCEMANAGER_H
