#include <iostream>
#include <cstring>
#include <cstdlib>

void foo(char cc1[]) {
    if (std::strcmp(cc1, "wxyz") != 0) std::abort();
}

void sfoo(char* sc1) {
    if (std::strcmp(sc1, "wxyz") != 0) std::abort();
}

void afoo(char (*ac1)[5]) {
    if (std::strcmp(ac1[0], "wxyz") != 0) std::abort();
}

int main() {
    char c0[5] = "wxyz"; // Equivalent of `character*4 :: c0`
    char* c1 = new char[5]; // Equivalent of `character*4, pointer :: c1`
    char (*c2)[5] = new char[1][5]; // Equivalent of `character*4, pointer :: c2(:)`

    // Directly calling foo with c0
    foo(c0);

    strcpy(c1, "wxyz");
    sfoo(c1);

    strcpy(c2[0], "wxyz");
    afoo(c2);

    delete[] c1; // Deallocate c1
    delete[] c2; // Deallocate c2

    std::cout << "All tests passed." << std::endl;

    return 0;
}