#include <iostream>
#include <string>
#include <array>

int main() {
    std::array<std::string, 18> titles = {
        "SMA", "PMA", "SRA", "PRA", "PER",
        "INC", "EPO", "ZPT", "ALB", "NL1",
        "NL2", "NL3", "NL4", "ECW", "ESW",
        "TED", "VOF", "DIL"
    };

    // Example usage: print all titles
    for (size_t i = 0; i < titles.size(); ++i) {
        std::cout << "Title(" << i+1 << "): " << titles[i] << std::endl;
    }

    return 0;
}