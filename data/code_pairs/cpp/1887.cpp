#include <cstdlib> // For abort
#include <bit> // For std::countl_zero and std::countr_zero
#include <climits> // For CHAR_BIT

int foo();

int main() {
    if (std::countl_zero(foo()) != CHAR_BIT * sizeof(int) - 1) std::abort();
    if (std::countl_zero(foo()) != CHAR_BIT * sizeof(int) - 2) std::abort();
    if (std::countr_zero(foo()) != 0) std::abort();
    if (std::countr_zero(foo()) != 2) std::abort();
    if (std::countr_zero(foo()) != 0) std::abort();
    if (std::countr_zero(foo()) != 1) std::abort();

    return 0;
}

int foo() {
    static int i = 0;
    i = i + 1;
    return i;
}