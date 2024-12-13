#include <fstream>
#include <array>
#include <iomanip>

void write_latlong_data(const std::array<double, 2>& lat, const std::array<double, 2>& longitude) {
    std::ofstream file("latlong.dat");

    if (file) {
        file << std::scientific << std::setprecision(16);
        for (int i = 0; i < 2; ++i) {
            file << std::setw(24) << lat[i];
        }
        for (int i = 0; i < 2; ++i) {
            file << std::setw(24) << longitude[i];
        }
        file << std::endl;
        file.close();
    } else {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
    }
}