#include <iostream>
#include <cstring>

bool isHelloWorld(const char* c) {
    return strcmp(c, "Hello, world!") == 0;
}

int main() {
    std::cout << "Test 1 (Expect True): " << std::boolalpha << isHelloWorld("Hello, world!") << std::endl;
    std::cout << "Test 2 (Expect False): " << std::boolalpha << isHelloWorld("Goodbye, world!") << std::endl;
    
    return 0;
}