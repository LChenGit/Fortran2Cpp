#include <iostream>
#include <cassert>

namespace constant {
    double sgam;
    double smue;
    double sram;
    double seps;
    double szero;
    double szero2;
    double somga;
}

int main() {
    using namespace constant;

    sgam = 1.0;
    smue = 2.0;
    sram = 3.0;
    seps = 4.0;
    szero = 5.0;
    szero2 = 6.0;
    somga = 7.0;

    std::cout << "sgam: " << sgam << std::endl;
    std::cout << "smue: " << smue << std::endl;
    std::cout << "sram: " << sram << std::endl;
    std::cout << "seps: " << seps << std::endl;
    std::cout << "szero: " << szero << std::endl;
    std::cout << "szero2: " << szero2 << std::endl;
    std::cout << "somga: " << somga << std::endl;

    assert(sgam == 1.0);
    assert(smue == 2.0);
    assert(sram == 3.0);
    assert(seps == 4.0);
    assert(szero == 5.0);
    assert(szero2 == 6.0);
    assert(somga == 7.0);

    std::cout << "All tests passed." << std::endl;

    return 0;
}