#include<iostream>
using namespace std;

// Function to mimic the first subroutine 'foo'
void foo(int a) {
    cout << "Hello from Fortran!!" << endl;
    cout << "input value a=" << a << endl;
}

// Function to mimic the second subroutine 'foovec'
void foovec(int a[], int size) {
    cout << "Hello from Fortran!!" << endl;
    cout << "input value avec=";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    // Example of calling foo
    cout << "Testing foo with input 5:" << endl;
    foo(5);
    
    // Example of calling foovec
    cout << "Testing foovec with input {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}:" << endl;
    int avec[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Example array
    foovec(avec, 10); // Passing array and its size
    
    return 0;
}