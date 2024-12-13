#ifndef RANDOM_IC_MOD_H
#define RANDOM_IC_MOD_H
#include <cstdlib>
#include <ctime>

class RandomICMod {
public:
    RandomICMod() {
        std::srand(static_cast<unsigned int>(std::time(nullptr))); // Use current time as seed for random generator
    }

    double generateRandom() const {
        return static_cast<double>(std::rand()) / RAND_MAX;
    }
};

#endif // RANDOM_IC_MOD_H