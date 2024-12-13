#include <iostream>

void mySub(int myInt);

int main() {
    int myInt = 10;

    mySub(myInt);

    if (myInt == 10) {
        std::cout << "Test passed: myInt remains unchanged." << std::endl;
    } else {
        std::cout << "Test failed: myInt was modified." << std::endl;
    }

    return 0;
}

void mySub(int myInt) {
    myInt = 11; // This modification should not affect the original variable.
}