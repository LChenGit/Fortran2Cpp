#include <iostream>
using namespace std;

int main() {
    int d[10] = {}; // Initialize all elements to 0

    for (int i = 1; i <= 5; ++i) {
        d[i-1] = i; // Arrays in C++ are 0-indexed; set the first five elements to their 1-based index
    }

    // Print the array elements
    for(int i = 0; i < 10; ++i) {
        cout << d[i] << " ";
    }
    cout << endl;
    
    return 0;
}