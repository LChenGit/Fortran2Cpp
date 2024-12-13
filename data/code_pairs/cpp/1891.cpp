#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

class Propagate {
public:
    using Complex = std::complex<double>;

    static void calculatePotential(std::vector<Complex>& V) {
        for (size_t i = 0; i < V.size(); ++i) {
            V[i] = Complex((i+1) * 0.01, -(i+1) * 0.01);
        }
    }
};

int main() {
    std::vector<Propagate::Complex> V(100);
    Propagate::calculatePotential(V);

    std::cout << "C++ Stdout: First element of V: " << V.front() << std::endl;

    return 0;
}