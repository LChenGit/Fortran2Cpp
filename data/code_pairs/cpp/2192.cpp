#include <iostream>

int numroc(int N, int NB, int IPROC, int ISRCPROC, int NPROCS);

int main() {
    test_numroc();
    return 0;
}

void test_numroc() {
    int result;

    // Test case 1
    result = numroc(100, 10, 0, 0, 4);
    std::cout << "Test case 1: " << result << std::endl;
    // Expected result: 30

    // Test case 2
    result = numroc(100, 10, 1, 0, 4);
    std::cout << "Test case 2: " << result << std::endl;
    // Expected result: 30

    // Test case 3
    result = numroc(100, 10, 2, 0, 4);
    std::cout << "Test case 3: " << result << std::endl;
    // Expected result: 20

    // Test case 4
    result = numroc(100, 10, 3, 0, 4);
    std::cout << "Test case 4: " << result << std::endl;
    // Expected result: 20
}

int numroc(int N, int NB, int IPROC, int ISRCPROC, int NPROCS) {
    int MYDIST = (NPROCS + IPROC - ISRCPROC) % NPROCS;
    int NBLOCKS = N / NB;
    int NUMROC = (NBLOCKS / NPROCS) * NB;
    int EXTRABLKS = NBLOCKS % NPROCS;

    if (MYDIST < EXTRABLKS) {
        NUMROC += NB;
    } else if (MYDIST == EXTRABLKS) {
        NUMROC += N % NB;
    }

    return NUMROC;
}