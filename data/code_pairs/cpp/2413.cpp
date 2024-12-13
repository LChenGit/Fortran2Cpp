#include <iostream>
#include <vector>
#include <cassert>

const int len_line_opt = 100;

void graphic_copy_line_opt(const std::vector<int> &line_style_from, std::vector<int> &line_style_to, int s) {
    if (s != 0) return;

    for (int l = 0; l < len_line_opt; ++l) {
        line_style_to[l] = line_style_from[l];
    }
}

void test_graphic_copy_line_opt() {
    std::vector<int> line_style_from(len_line_opt);
    std::vector<int> line_style_to(len_line_opt, 0);
    int s = 0;

    // Initialize test data
    for (int i = 0; i < len_line_opt; ++i) {
        line_style_from[i] = i + 1;
    }

    // Call the function
    graphic_copy_line_opt(line_style_from, line_style_to, s);

    // Verify the result
    for (int i = 0; i < len_line_opt; ++i) {
        assert(line_style_to[i] == line_style_from[i] && "Test failed");
    }

    std::cout << "Test passed" << std::endl;
}

int main() {
    test_graphic_copy_line_opt();
    return 0;
}