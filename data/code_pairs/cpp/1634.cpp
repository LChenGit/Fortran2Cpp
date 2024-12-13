#include <iostream>
#include <string>

std::string getHello() {
    return "hello";
}

int main() {
    std::cout << getHello() << std::endl;
    return 0;
}