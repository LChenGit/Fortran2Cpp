#include <iostream>
#include <string>

std::string classifyNumber(int number) {
    if (number > 0) {
        return "Positive";
    } else if (number < 0) {
        return "Negative";
    } else {
        return "Zero";
    }
}

int main() {
    std::cout << classifyNumber(5) << std::endl;
    std::cout << classifyNumber(-3) << std::endl;
    std::cout << classifyNumber(0) << std::endl;
    return 0;
}