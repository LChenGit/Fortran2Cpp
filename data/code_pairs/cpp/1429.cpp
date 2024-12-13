#include <vector>
#include <iostream>

class ThreeBody {
public:
    void step(std::vector<std::vector<float>>& x) {
        for (auto& row : x) {
            std::fill(row.begin(), row.end(), 1.0f);
        }
    }

    void run() {
        const int n = 2, d = 2;
        std::vector<std::vector<float>> x_hq(n, std::vector<float>(d));
        step(x_hq);

        std::cout << "Matrix x_hq filled with:" << std::endl;
        for (const auto& row : x_hq) {
            for (float val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    ThreeBody simulation;
    simulation.run();

    return 0;
}