#include <iostream>

void modifyArray(float* array, int size) {
    // Modify the first element of the array
    if (size > 0)
        array[0] = 0.8f;
}

int main() {
    float a[5] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    
    std::cout << "Original array 'a':" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << a[i] << std::endl;
    }
    
    modifyArray(a, 5);
    
    std::cout << "
Modified array 'a' after calling modifyArray:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << a[i] << std::endl;
    }
    
    return 0;
}