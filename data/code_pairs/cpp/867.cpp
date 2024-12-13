// square.cpp
#include <iostream>

float square(float x) {
    return x * x;
}

int main() {
    float number = 4.0f;
    float result = square(number);
    std::cout << "Square of " << number << " is " << result << std::endl;
    return 0;
}