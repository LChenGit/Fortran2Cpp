#include <iostream>
using namespace std;

void testBlock(float& i) {
    do {
        if (i > 7.7f) {
            break;
        } else {
            i = 2.2f;
        }
    } while (false);
    
    cout << "Result: " << i << endl;
}

int main() {
    // Test 1: i > 7.7
    cout << "Test 1: i = 9.9" << endl;
    float i = 9.9f;
    testBlock(i);

    // Test 2: i <= 7.7
    cout << "Test 2: i = 6.6" << endl;
    i = 6.6f;
    testBlock(i);

    return 0;
}