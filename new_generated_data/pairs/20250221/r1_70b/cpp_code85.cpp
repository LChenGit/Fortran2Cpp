#include <iostream>
#include <cassert>
#include <iomanip>  // For setprecision and fixed

using namespace std;

double addNumbers(double a, double b) {
    return a + b;
}

int main() {
    double x = 5.0;
    double y = 3.0;
    double result = addNumbers(x, y);

    // Using fixed and setprecision for formatted output
    cout << "The sum of " << fixed << setprecision(2) << x 
         << " and " << y << " is: " << result << endl;

    // Simple unit test
    assert(result == 8.0 && "Unit test failed: Incorrect sum.");

    return 0;
}