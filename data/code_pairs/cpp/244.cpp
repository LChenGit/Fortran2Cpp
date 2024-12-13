#include <iostream>

int main() {
    goto label3; // Direct jump to label3
    
    label3:
    std::cout << "Label 3 reached";
    return 0;
}