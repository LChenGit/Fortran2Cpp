#include <iostream>
#include <array>
#include <string>

class Deriv {
public:
    std::string name;
    Deriv(const std::string& name = "") : name(name) {}
};

std::array<std::string, 2> DEF_ECOSYSTEMS = {"Gridxxxx", "StringYY"};

Deriv DepEcoSystem(DEF_ECOSYSTEMS[0]);

void Init_EcoSystems() {
    int i = 1; // Adjusted for 0-based indexing
    DepEcoSystem = Deriv(DEF_ECOSYSTEMS[i]);
}

int main() {
    // Initial condition check
    if (DepEcoSystem.name != "Gridxxxx") {
        std::cerr << "Error code: 1\n";
        return 1;
    }
    
    DepEcoSystem.name = "ABCDEFGHIJ";
    Init_EcoSystems();
    
    // After Init_EcoSystems
    if (DepEcoSystem.name != "StringYY") {
        std::cerr << "Error code: 2\n";
        return 2;
    }
    
    return 0;
}