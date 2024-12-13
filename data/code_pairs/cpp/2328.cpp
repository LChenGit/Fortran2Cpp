#include <iostream>
#include <vector>
#include <string>
#include <array>

// Assuming the definitions of SRK, MX_NM, Rod, Reflector are provided in these headers.
struct Rod {
    // Dummy implementation for demonstration
};

struct Reflector {
    // Dummy implementation for demonstration
};

namespace Cores {

class Core {
public:
    std::string name;
    std::string geom;
    std::array<std::string, 3> bc;
    std::vector<std::vector<Rod>> grid;
    std::vector<Reflector> refs;
    float pwr;
    std::array<float, 2> pitch;

    void init(const std::string& name, const std::string& geom, const std::array<int, 2>& dimen, const std::array<float, 2>& pitch, const std::array<std::string, 3>& bc) {
        this->name = name;
        this->geom = geom;
        this->pitch = pitch;
        this->bc = bc;
        this->grid.resize(dimen[0], std::vector<Rod>(dimen[1]));
        // Initialization of grid elements and refs not shown for brevity
    }

    void clear() {
        grid.clear();
        refs.clear();
    }
};

} // namespace Cores

int main() {
    Cores::Core core;
    core.init("TestCore", "Geometry", {10, 10}, {1.0f, 1.5f}, {"BC1", "BC2", "BC3"});

    std::cout << "Core name: " << core.name << "\n";
    std::cout << "Core geometry: " << core.geom << "\n";
    std::cout << "Core boundary conditions: " << core.bc[0] << " " << core.bc[1] << " " << core.bc[2] << "\n";
    std::cout << "Core pitch: " << core.pitch[0] << ", " << core.pitch[1] << "\n";

    core.clear();
    std::cout << "Core cleared successfully." << std::endl;

    return 0;
}