#include <iostream>
using namespace std;

// Declare CHARVAL globally
char CHARVAL[26];

void rv_initialize();

int main() {
    rv_initialize();

    for (int i = 0; i < 26; ++i) {
        char expected_char = 'A' + i;
        if (CHARVAL[i] != expected_char) {
            cout << "Test failed at index " << i << endl;
            cout << "Expected: " << expected_char << endl;
            cout << "Received: " << CHARVAL[i] << endl;
            return 1; // Exit with error code
        }
    }

    cout << "All test cases passed." << endl;
    return 0;
}

void rv_initialize() {
    for (int i = 0; i < 26; ++i) {
        CHARVAL[i] = 'A' + i;
    }
}