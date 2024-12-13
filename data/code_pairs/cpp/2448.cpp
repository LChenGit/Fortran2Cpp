#include <vector>
#include <iostream>

class Configuration {
public:
    int natoms = 0;
    std::vector<float> xmass;

    void init_atoms(int n) {
        natoms = n;
        xmass.resize(natoms);
        for (int i = 0; i < natoms; ++i) {
            xmass[i] = static_cast<float>(i + 1);
        }
    }

    void print_first_atom_mass() const {
        if (!xmass.empty()) {
            std::cout << "xmass[0]: " << xmass[0] << std::endl;
        }
    }
};