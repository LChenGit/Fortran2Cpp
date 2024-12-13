#include <iostream>

int x;
int y;

void setXfromY() {
    y = 5; // Assign a value to y
    x = y; // Assign the value of y to x
}

int main() {
    setXfromY(); // Perform the operation to set x from y
    std::cout << "x: " << x << ", y: " << y << std::endl; // Print x and y
    
    return 0;
}