#include <iostream>
#include <vector>

void fixMap(std::vector<int>& map) {
    for (size_t i = 0; i < map.size(); ++i) {
        if (map[i] == 0) map[i] = static_cast<int>(i) + 1; // +1 to match Fortran 1-based indexing
    }
}

int main() {
    std::vector<int> map = {0, 2, 0, 4, 0};
    fixMap(map);

    for (size_t i = 0; i < map.size(); ++i) {
        std::cout << "map[" << i << "] = " << map[i] << std::endl;
    }

    return 0;
}