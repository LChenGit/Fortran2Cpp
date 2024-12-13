#include <iostream>
#include <vector>
#include <cmath>

void mover(const std::vector<std::vector<double>>& c1, int na1, const std::vector<std::vector<double>>& c2, int na2, double cut, int np2, std::vector<int>& atom_list) {
    double x1, y1, z1, x2, y2, z2, dist;
    int count = 0;

    for (int i = 0; i < na1; ++i) {
        x1 = c1[i][0];
        y1 = c1[i][1];
        z1 = c1[i][2];
        for (int j = 0; j < na2; ++j) {
            x2 = c2[j][0];
            y2 = c2[j][1];
            z2 = c2[j][2];
            double dx2 = (x2 - x1) * (x2 - x1);
            double dy2 = (y2 - y1) * (y2 - y1);
            double dz2 = (z2 - z1) * (z2 - z1);
            dist = std::sqrt(dx2 + dy2 + dz2);
            if (dist < cut) {
                atom_list[count] = j + 1; // +1 for 1-based indexing consistency with Fortran
                ++count;
            }
        }
    }

    std::cout << "C++: COUNT = " << count << std::endl;
}

int main() {
    int na1 = 2, na2 = 2, np2 = 2;
    double cut = 1.5;
    std::vector<std::vector<double>> c1 = {{0.0, 0.0, 0.0}, {3.0, 3.0, 3.0}};
    std::vector<std::vector<double>> c2 = {{1.0, 1.0, 1.0}, {4.0, 4.0, 4.0}};
    std::vector<int> atom_list(np2, 0);

    mover(c1, na1, c2, na2, cut, np2, atom_list);

    std::cout << "atom_list: ";
    for (auto val : atom_list) std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}