#include <array>
#include <algorithm>

int main() {
    std::array<int, 4> i = {1, 1, 1, 1};
    std::array<int, 4> z = {1, 1, -1, -1};

    std::transform(z.begin(), z.end(), z.begin(), [](int elem) {
        return elem < 0 ? 1 : elem;
    });

    if (!std::equal(z.begin(), z.end(), i.begin())) {
        return 1; // Exits with code 1 if arrays are not equal
    }

    return 0; // Normal program termination
}