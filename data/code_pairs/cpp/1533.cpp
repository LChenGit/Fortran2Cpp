#include <iostream>
#include <vector>

void per_getcof(std::vector<double>& coffs, int npt, std::vector<double>& g, int m) {
    for (int j = 0; j < m; ++j) {
        g[j] = -coffs[j + 1];
    }
}

int main() {
    std::vector<double> coffs = {1.0, 2.0, 3.0, 4.0, 5.0};
    int npt = 5;
    int m = 4;
    std::vector<double> g(m);

    per_getcof(coffs, npt, g, m);

    std::cout << "g:" << std::endl;
    for (int i = 0; i < m; ++i) {
        std::cout << g[i] << std::endl;
    }

    return 0;
}