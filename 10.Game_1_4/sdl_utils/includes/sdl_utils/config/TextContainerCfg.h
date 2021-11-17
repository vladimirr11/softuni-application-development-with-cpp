#ifndef TEXTCONTAINERCFG_H
#define TEXTCONTAINERCFG_H

// C system includes

// C++ system includes
#include <cstdint>
#include <string>
#include <unordered_map>

// Third-party includes

// Own includes

// Forward declarations

struct FontCfg {
    std::string location;
    int32_t fontSize = 0;
};

struct TextContainerCfg {
    std::unordered_map<int32_t, FontCfg> textConfigs;
};

#endif // !TEXTCONTAINERCFG_H
