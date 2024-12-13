#include <iostream>
#include <cassert>

char chr_achr(int ascii) {
    const int DEL = 127;
    const int NUL = 0;

    if (ascii > NUL && ascii <= DEL) {
        return static_cast<char>(ascii);
    } else {
        return static_cast<char>(NUL);
    }
}