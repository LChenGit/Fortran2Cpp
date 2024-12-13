#include <iostream>
using namespace std;

void testVariable(int value) {
    if (value == 10) {
        cout << "Test Passed: ii is correctly assigned the value 10." << endl;
    } else {
        cout << "Test Failed: ii is not correctly assigned the value 10." << endl;
    }
}

int main() {
    int ii = 10;
    testVariable(ii);
    return 0;
}