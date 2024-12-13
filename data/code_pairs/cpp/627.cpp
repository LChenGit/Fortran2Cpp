#include <cstdint> // For std::int16_t
#include <iostream>

const int XXTARH = 10;

struct TARS {
    std::int16_t FTAR;
    std::int16_t TARHIB;
    std::int16_t TARBUF[XXTARH];
};

TARS tars;

void SetValues() {
    tars.FTAR = 1;
    tars.TARHIB = 2;
    tars.TARBUF[0] = 10;
    tars.TARBUF[1] = 20;
}

void PrintValues() {
    std::cout << "FTAR = " << tars.FTAR << std::endl;
    std::cout << "TARHIB = " << tars.TARHIB << std::endl;
    std::cout << "TARBUF[0] = " << tars.TARBUF[0] << std::endl;
    std::cout << "TARBUF[1] = " << tars.TARBUF[1] << std::endl;
}

int main() {
    SetValues();
    PrintValues();
    return 0;
}