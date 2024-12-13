// Barrel.hpp
#include <vector>
#include <cmath>

class Barrel {
private:
    int nvats;
    float vol;
    float strength;
    std::vector<std::vector<float>> vat;

public:
    Barrel(float strength) : nvats(0), vol(119.2), strength(strength) {}

    ~Barrel() {}

    int get_nvats() const { return nvats; }
    float get_vol() const { return vol; }
    float get_strength() const { return strength; }
    void distil(float volume) {
        vat.clear();
        nvats = std::ceil(volume / vol);
        vat.resize(nvats, std::vector<float>(2));  // Assuming 2 columns for simplicity
    }
};

// main.cpp
#include <iostream>
#include "Barrel.hpp"

int main() {
    Barrel myBarrel(50.0);
    myBarrel.distil(500.0);

    std::cout << "Number of vats: " << myBarrel.get_nvats() << std::endl;
    std::cout << "Volume per vat: " << myBarrel.get_vol() << std::endl;
    std::cout << "Overall strength: " << myBarrel.get_strength() << std::endl;

    return 0;
}