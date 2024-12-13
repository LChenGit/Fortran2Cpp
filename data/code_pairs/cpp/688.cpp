#include <iostream>
#include <complex>
using namespace std;

void testInteger(int I) {
    if (I > 0) {
        cout << "INTEGER branch 300" << endl;
    } else if (I == 0) {
        cout << "INTEGER branch 200" << endl;
    } else {
        cout << "INTEGER branch 100" << endl;
    }
}

void testComplex(complex<double> Z) {
    if (real(Z) != 0 || imag(Z) != 0) {
        cout << "COMPLEX branch 301" << endl;
    } else {
        cout << "COMPLEX branch 201" << endl;
    }
}

void testLogical(bool L) {
    if (L) {
        cout << "LOGICAL branch 302" << endl;
    } else {
        cout << "LOGICAL branch 202" << endl;
    }
}

void testArray(int B[2]) {
    bool anyNonZero = B[0] != 0 || B[1] != 0;
    if (anyNonZero) {
        cout << "ARRAY branch 303" << endl;
    } else {
        cout << "ARRAY branch 203" << endl;
    }
}

int main() {
    // Test INTEGER condition
    testInteger(0);
    testInteger(-1);
    testInteger(1);

    // Test COMPLEX condition
    testComplex(complex<double>(0, 0));
    testComplex(complex<double>(1, 0));

    // Test LOGICAL condition
    testLogical(true);
    testLogical(false);

    // Test ARRAY condition
    int B1[2] = {0, 0};
    testArray(B1);
    int B2[2] = {1, 0};
    testArray(B2);

    return 0;
}