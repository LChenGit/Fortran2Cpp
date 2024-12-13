#include <iostream>
#include <cassert>

class M1 {
public:
    static int G1() {
        return 1;
    }

    static int G2() {
        return 1;
    }

    static int G3() {
        return 1;
    }
};

class P1 {
public:
    static int F1() {
        return 1;
    }

    static int F2() {
        return 1;
    }
};

// Unit tests for the translated code
int main() {
    // Testing the M1 class functions
    assert(M1::G1() == 1);
    std::cout << "M1::G1 test passed." << std::endl;

    assert(M1::G2() == 1);
    std::cout << "M1::G2 test passed." << std::endl;

    assert(M1::G3() == 1);
    std::cout << "M1::G3 test passed." << std::endl;

    // Testing the P1 class functions
    assert(P1::F1() == 1);
    std::cout << "P1::F1 test passed." << std::endl;

    assert(P1::F2() == 1);
    std::cout << "P1::F2 test passed." << std::endl;

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}