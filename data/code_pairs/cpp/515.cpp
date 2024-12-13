#include <iostream>
#include <cassert>

int testLogic() {
    int i, j;
    
    for (i = 1; i <= 10; ++i) {
        j = i;
    }

    j = 20;

    for (i = 1; i <= 10; ++i) {
        if (j < 15) {
            j = i;
            std::cout << "HERE" << std::endl;
        }
    }
    
    return j;
}

int main() {
    // Testing the logic
    assert(testLogic() == 20); // We expect j to be 20 at the end of the testLogic function

    std::cout << "All tests passed." << std::endl;
    return 0;
}