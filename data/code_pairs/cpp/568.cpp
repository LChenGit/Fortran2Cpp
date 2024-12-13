#ifndef PARA_H
#define PARA_H

#include <string>

namespace para {
    std::string bobo(int n) {
        std::string original = "1234567890";
        return original.substr(0, n);
    }
}

#endif // PARA_H