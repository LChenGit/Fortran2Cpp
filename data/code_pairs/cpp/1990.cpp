#ifndef CLAENV_H
#define CLAENV_H

#include <array>

class CLAENV {
public:
    static std::array<int, 100>& IPARMS() {
        static std::array<int, 100> instance;
        return instance;
    }
};

void XLAENV(int ISPEC, int NVALUE) {
    if (ISPEC >= 1 && ISPEC <= 8) {
        CLAENV::IPARMS()[ISPEC - 1] = NVALUE; // Array indexing starts at 0 in C++
    }
}

#endif // CLAENV_H