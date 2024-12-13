#include <iostream>

void ugetio(int& iopt, int& nin, int& nout) {
    static int nind = 1;
    static int noutd = 2;

    if (iopt == 3) {
        noutd = nout;
    } else if (iopt == 2) {
        nind = nin;
    } else if (iopt == 1) {
        nin = nind;
        nout = noutd;
    }
}

int main() {
    int nin, nout;

    // Test iopt = 1
    ugetio(1, nin, nout);
    std::cout << "Test iopt=1: nin=" << nin << " nout=" << nout << std::endl;
    
    // Test iopt = 2
    nin = 10;
    ugetio(2, nin, nout);
    std::cout << "Test iopt=2: nin=" << nin << " nout=" << nout << std::endl;
    
    // Test iopt = 3
    nout = 20;
    ugetio(3, nin, nout);
    std::cout << "Test iopt=3: nin=" << nin << " nout=" << nout << std::endl;

    return 0;
}