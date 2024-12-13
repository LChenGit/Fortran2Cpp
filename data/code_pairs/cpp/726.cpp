#include <iostream>
#include <cassert>

void Mouv(double& oper0, double oper1, double& resul) {
    resul = oper0 + oper1;
    oper0 = 8.0;
}

void Pas_1() {
    double oper0 = 3.0;
    double oper1 = 4.0;
    double resul; // Note: resul is uninitialized here, so its initial value is indeterminate.

    std::cout << "--- Avant --- oper0: " << oper0 << " oper1: " << oper1 << " resul: " << resul << std::endl;

    Mouv(oper0, oper1, resul);

    std::cout << "--- Apres --- oper0: " << oper0 << " oper1: " << oper1 << " resul: " << resul << std::endl;
}

void testMouv() {
    double oper0 = 3.0;
    double oper1 = 4.0;
    double resul;

    Mouv(oper0, oper1, resul);

    assert(oper0 == 8.0);
    assert(oper1 == 4.0); // oper1 should remain unchanged because it's passed by value
    assert(resul == 7.0); // resul should be the sum of the original oper0 and oper1

    std::cout << "All tests passed successfully." << std::endl;
}

int main() {
    // Pas_1(); Uncomment to run the original function
    testMouv(); // Run the test
    return 0;
}