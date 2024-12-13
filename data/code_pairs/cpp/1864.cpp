#include <iostream>

void dummy_subroutine() {
    for (int i = 1; i <= 10; ++i) {
        std::cout << "First loop body: " << i << std::endl;
    }

    for (int i = 1; i <= 10; ++i) {
        std::cout << "Second loop body: " << i << std::endl;
    }
}

int main() {
    dummy_subroutine();
    
    return 0;
}