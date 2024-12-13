#include <iostream>
#include <string>
#include <cassert>

int main() {
    // Test 1: .not..true.
    assert(!true == false);
    std::cout << "Test 1 passed" << std::endl;

    // Test 2: .not..false.
    assert(!false == true);
    std::cout << "Test 2 passed" << std::endl;

    // Test 3: .not..false..eqv..true.
    assert((!false == true) == true);
    std::cout << "Test 3 passed" << std::endl;

    // Test 4: 'hello' == 'hello'
    assert(std::string("hello") == std::string("hello"));
    std::cout << "Test 4 passed" << std::endl;

    // Test 5: 'hello' != 'world'
    assert(!(std::string("hello") == std::string("world")));
    std::cout << "Test 5 passed" << std::endl;

    // Test 6: 'hello world' == 'hello' + ' world'
    assert(std::string("hello world") == std::string("hello") + std::string(" world"));
    std::cout << "Test 6 passed" << std::endl;

    return 0;
}