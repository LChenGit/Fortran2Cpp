#ifndef STORAGE_H
#define STORAGE_H

#include <vector>

class Storage {
public:
    Storage() = default;
    void AllocateMemory(int totalPolynomialOrder);

    std::vector<float> Q;    // Public for testing purposes.
    std::vector<float> QDot; // Public for testing purposes.
#ifdef NAVIER_STOKES
    std::vector<float> dQ;   // Public for testing purposes.
#endif
};

#endif // STORAGE_H