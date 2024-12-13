#include <iostream>

int getII() {
    return 10; // Function encapsulating the logic for testability
}

int main() {
    std::cout << "Value of ii: " << getII() << std::endl;
    return 0;
}