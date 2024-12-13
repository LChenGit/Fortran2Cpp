#include <iostream>
using namespace std;

void fill_array(int a[], int size);

// Unit test function
bool test_fill_array() {
    const int size = 10;
    int a[size];
    fill_array(a, size);
    
    for(int i = 0; i < size; ++i) {
        if (a[i] != i + 1) {
            return false;
        }
    }
    return true;
}

int main() {
    if (test_fill_array()) {
        cout << "Test passed." << endl;
    } else {
        cout << "Test failed." << endl;
    }

    return 0;
}

void fill_array(int a[], int size) {
    for(int i = 0; i < size; ++i) {
        a[i] = i + 1;
    }
}