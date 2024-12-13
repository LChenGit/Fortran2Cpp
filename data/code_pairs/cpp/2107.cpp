#include <iostream>

// Function declaration
void suba(int* c);

int main() {
    int c[100]; // Declaring an array of integers
    c[0] = 1;   // Assigning the value 1 to the first element of the array (zero-indexed in C++)
    suba(c);    // Calling the function suba with the array c as argument
    return 0;
}

// Definition of the suba function
void suba(int* c) {
    std::cout << *c << std::endl; // Printing the value of the first element of the array
}