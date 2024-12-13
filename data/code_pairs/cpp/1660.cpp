#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cassert>

// Constants
const int sx = 640, sy = 480, crop = 100;
const double ox = 320.0, oy = 240.0;

int main() {
    // Initialize the screen with default values
    std::vector<std::vector<double>> screen(sx, std::vector<double>(sy, -99999.0));

    // Apply calculation within the specified bounds
    for (int y = 0; y < sy; ++y) {
        for (int x = 0; x < sx; ++x) {
            if (x >= crop && x < sx - crop && y >= crop && y < sy - crop) {
                screen[x][y] = std::pow(x - ox, 2) + std::pow(y - oy, 2);
            }
        }
    }

    // Writing to a file
    std::ofstream file("test.bin", std::ios::binary);
    assert(file.is_open() && "Failed to open test.bin for writing");

    int width = sx - 2 * crop;
    int height = sy - 2 * crop;
    file.write(reinterpret_cast<const char*>(&width), sizeof(width));
    file.write(reinterpret_cast<const char*>(&height), sizeof(height));

    for (int y = crop; y < sy - crop; ++y) {
        for (int x = crop; x < sx - crop; ++x) {
            file.write(reinterpret_cast<const char*>(&screen[x][y]), sizeof(screen[x][y]));
        }
    }
    file.close();

    std::cout << "Test Passed: The values in 'test.bin' are correct.";

    return 0;
}