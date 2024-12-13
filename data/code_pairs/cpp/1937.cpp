#include <iostream>
#include <cassert>
using namespace std;

int getEndxyz(bool condition) {
    int endxyz = 1;
    if (condition) {
        endxyz = 2;
    }
    return endxyz;
}

void testEndxyz() {
    assert(getEndxyz(true) == 2 && "Test when condition is true. Expected: 2");
    assert(getEndxyz(false) == 1 && "Test when condition is false. Expected: 1");
    
    // If this message prints, all tests passed
    cout << "All tests passed." << endl;
}

int main() {
    testEndxyz();
    return 0;
}