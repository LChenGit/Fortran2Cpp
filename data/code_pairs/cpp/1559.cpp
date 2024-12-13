#ifndef GREET_WORLD_H
#define GREET_WORLD_H

#include <string>

namespace greet_mod {
    void greet(const std::string& name);
}

namespace world_mod {
    extern std::string world;
}

#endif // GREET_WORLD_H