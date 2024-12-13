#include <iostream>
#include <complex>
using namespace std;

// The SCABS1 function
double SCABS1(const complex<double>& Z) {
    return abs(real(Z)) + abs(imag(Z));
}

int main() {
    // Test case 1
    complex<double> Z1(3.0, 4.0);
    cout << "Test case 1: (3,4) - Expected: 7, Got: " << SCABS1(Z1) << endl;

    // Test case 2
    complex<double> Z2(-1.5, 2.5);
    cout << "Test case 2: (-1.5,2.5) - Expected: 4, Got: " << SCABS1(Z2) << endl;

    // Add more test cases as needed

    return 0;
}