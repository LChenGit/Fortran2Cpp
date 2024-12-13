#include <iostream>
#include <cassert>
using namespace std;

void modify_array(int i[3]) {
    for (int idx = 0; idx < 3; idx++) {
        if (i[idx] > 1) {
            i[idx] *= 2;
        } else {
            i[idx] *= 3;
        }
    }
}

int main() {
    int i[3] = {1, 2, 3};
    int expected[3] = {3, 4, 6};

    modify_array(i);

    bool passed = true;
    for (int idx = 0; idx < 3; idx++) {
        if (i[idx] != expected[idx]) {
            passed = false;
            break;
        }
    }

    if (passed) {
        cout << "Test passed." << endl;
    } else {
        cout << "Test failed. Result: ";
        for (int idx = 0; idx < 3; idx++) {
            cout << i[idx] << " ";
        }
        cout << endl;
    }

    return 0;
}