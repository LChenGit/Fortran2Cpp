#include <iostream>
#include <cassert>

int npreroc(int n, int nb, int iproc, int isrcproc, int nprocs) {
    int mydist = (nprocs + iproc - isrcproc) % nprocs;
    int nblocks = n / nb;
    int result = (nblocks / nprocs) * nb;
    int extrablks = nblocks % nprocs;

    if (mydist < extrablks) {
        result += nb * (mydist + 1);
    } else {
        result += extrablks * nb + n % nb;
    }

    return result;
}

int main() {
    std::cout << "Test 1: Expected 250, Got " << npreroc(1000, 10, 1, 0, 4) << std::endl;
    assert(npreroc(1000, 10, 1, 0, 4) == 250);

    std::cout << "Test 2: Expected 20, Got " << npreroc(100, 20, 1, 1, 5) << std::endl;
    assert(npreroc(100, 20, 1, 1, 5) == 20);

    std::cout << "All tests passed." << std::endl;

    return 0;
}