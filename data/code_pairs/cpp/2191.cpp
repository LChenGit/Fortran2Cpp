#include <iostream>

int owner_block(int ig, int nx, int np) {
    int q = nx / np;
    int r = nx % np;

    if (ig <= (q + 1) * r) {
        return (ig - 1) / (q + 1);
    } else {
        return ((ig - 1 - r) / q) + r;
    }
}

int owner_cyclic(int ig, int nx, int np) {
    return (ig - 1) % np;
}

int owner_block_cyclic(int INDXGLOB, int NB, int NPROCS) {
    return ((INDXGLOB - 1) / NB) % NPROCS;
}

int main() {
    std::cout << "owner_block(5, 20, 4) = " << owner_block(5, 20, 4) << std::endl;
    std::cout << "owner_cyclic(5, 20, 4) = " << owner_cyclic(5, 20, 4) << std::endl;
    std::cout << "owner_block_cyclic(5, 4, 4) = " << owner_block_cyclic(5, 4, 4) << std::endl;
    return 0;
}