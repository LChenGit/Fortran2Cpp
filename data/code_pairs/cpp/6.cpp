#ifndef PARAM_H
#define PARAM_H

#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>

class Param {
public:
    static const int ACCU = std::numeric_limits<double>::digits10;
    static const int ALL_MF = 42;
    static const double MU_TOLERANCE;
    static const double DGEN_TOLERANCE;

    struct Rotor {
        double A, B, C;
    };

    struct Potential {
        double Vj, Vk, Vm;
    };

    static bool is_linear(const Rotor& mol) {
        return mol.A == 0.0 && mol.C == 0.0;
    }

    static void set_k_limit(int k) {
        if (k != 0 && k != 4) {
            throw std::invalid_argument("set_k_limit(): Only K=0 or K=4 supported at the moment");
        }
        K_LIMIT = k;
    }

    static int get_k_limit() {
        return K_LIMIT;
    }

    static void setdim(int i) {
        dim = i;
    }

    static int getdim() {
        return dim;
    }

private:
    static int dim;
    static int K_LIMIT;
};

const double Param::MU_TOLERANCE = 1e-4;
const double Param::DGEN_TOLERANCE = 1e-9;
int Param::dim = 0;
int Param::K_LIMIT = 4;

#endif // PARAM_H