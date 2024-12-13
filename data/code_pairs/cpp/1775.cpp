#ifndef BLADE_H
#define BLADE_H

#include <vector>

class Blade {
public:
    std::vector<double> C;
    std::vector<double> DR;
    double R;
    int NB;

    Blade() = default;
    ~Blade() = default;

    void allocate(int sizeC, int sizeDR) {
        C.resize(sizeC);
        DR.resize(sizeDR);
    }
};

#endif // BLADE_H