#include <iostream>
#include <cassert>

int main() {
    int seconds_in_a_day;

    // Test 1
    seconds_in_a_day = 24*60*60;
    assert(seconds_in_a_day == 86400);
    std::cout << "Test 1 passed." << std::endl;

    // Test 2
    seconds_in_a_day = 24*60*60;
    assert(seconds_in_a_day == 86400);
    std::cout << "Test 2 passed." << std::endl;

    // Test 3: Checking a long string
    std::string longString = "This is a really long string, that normally would not fit on a single line.";
    assert(longString == "This is a really long string, that normally would not fit on a single line.");
    std::cout << "Test 3 passed." << std::endl;

    return 0;
}