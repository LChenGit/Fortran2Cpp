#include <iostream>
#include <optional>
#include <cstdlib>
#include <cassert>

class MyObj {
public:
    int myfunc(std::optional<int> status = std::nullopt) const {
        if (status.has_value()) {
            return 1; // Behavior when an argument is provided
        } else {
            return 2; // Default behavior when no argument is provided
        }
    }
};

int main() {
    MyObj myinstance;

    // Test case 1: Call myfunc without arguments
    int res = myinstance.myfunc();
    assert(res == 2 && "Test case 1 failed");

    // Test case 2: Call myfunc with an argument
    res = myinstance.myfunc(1);
    assert(res == 1 && "Test case 2 failed");

    std::cout << "All tests passed." << std::endl;

    return 0;
}