#include <iostream>
#include <vector>

void linvec10(const std::vector<std::vector<double>>& vec, const std::vector<int>& konl,
              std::vector<double>& vecl, const std::vector<std::vector<double>>& shp) {
    for (int j = 0; j < 3; ++j) {
        vecl[j] =
            (shp[3][0] + (shp[3][4] + shp[3][6] + shp[3][7]) / 2.0) * vec[j][konl[0] - 1]
            + (shp[3][1] + (shp[3][4] + shp[3][5] + shp[3][8]) / 2.0) * vec[j][konl[1] - 1]
            + (shp[3][2] + (shp[3][5] + shp[3][6] + shp[3][9]) / 2.0) * vec[j][konl[2] - 1]
            + (shp[3][3] + (shp[3][7] + shp[3][8] + shp[3][9]) / 2.0) * vec[j][konl[3] - 1];
    }
}

int main() {
    std::vector<std::vector<double>> vec = {
        {1.0, 2.0, 3.0, 4.0},
        {5.0, 6.0, 7.0, 8.0},
        {9.0, 10.0, 11.0, 12.0}
    };
    std::vector<int> konl = {1, 2, 3, 4};
    std::vector<double> vecl(3, 0.0);
    std::vector<std::vector<double>> shp = {
        {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0},
        {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0},
        {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0},
        {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0}
    };

    linvec10(vec, konl, vecl, shp);

    std::cout << "vecl = ";
    for(double v : vecl) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}