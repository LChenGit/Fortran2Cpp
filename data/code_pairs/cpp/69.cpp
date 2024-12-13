#include <array>
#include <iostream>
#include <algorithm> // For std::copy

struct t {
    bool valid;
    int x, y;
};

int main() {
    std::array<t, 5> s{{
        {true, 1, 10}, // Initializing 's' with some values
        {true, 2, 20},
        {true, 3, 30},
        {true, 4, 40},
        {true, 5, 50}
    }};
    std::array<t, 5> d;

    // Copy 's' to 'd'
    std::copy(s.begin(), s.end(), d.begin());

    // Test to check if 's' and 'd' match
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i].valid != d[i].valid || s[i].x != d[i].x || s[i].y != d[i].y) {
            std::cout << "Test failed at index " << i << std::endl;
            return 1;
        }
    }

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}