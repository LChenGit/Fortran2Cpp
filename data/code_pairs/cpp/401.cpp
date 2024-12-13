#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>

std::vector<std::vector<std::vector<int>>> create3DArray() {
    std::vector<std::vector<std::vector<int>>> arr(4, std::vector<std::vector<int>>(4, std::vector<int>(4)));
    int val = 1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                arr[i][j][k] = val++;
            }
        }
    }
    return arr;
}

void test(const std::string& testName, const auto& expected, const auto& result) {
    if (expected == result) {
        std::cout << testName << " passed." << std::endl;
    } else {
        std::cout << testName << " failed." << std::endl;
        std::exit(1);
    }
}

int main() {
    auto a = create3DArray();
    std::vector<int> v = {3, 0, 2, 1}; // Adjusted for 0-based indexing

    // Assuming direct slicing for simplicity and clarity
    std::vector<std::vector<int>> b1{{a[0][1][1], a[0][1][2], a[0][1][3]},
                                     {a[1][1][1], a[1][1][2], a[1][1][3]},
                                     {a[2][1][1], a[2][1][2], a[2][1][3]}};
    std::vector<int> b2{a[1][3][0], a[1][3][3], a[1][3][2]};
    std::vector<int> b2b{a[0][1][3], a[3][1][3], a[2][1][3]};
    std::vector<int> b3{a[0][v[0]][2], a[0][v[1]][2], a[0][v[2]][2], a[0][v[3]][2]};
    std::vector<std::vector<int>> b4{{a[v[1]][1][1], a[v[1]][1][2], a[v[1]][1][3]},
                                     {a[v[3]][1][1], a[v[3]][1][2], a[v[3]][1][3]},
                                     {a[v[2]][1][1], a[v[2]][1][2], a[v[2]][1][3]}};

    // Testing
    test("b1", std::vector<std::vector<int>>{{21, 22, 23}, {37, 38, 39}, {53, 54, 55}}, b1);
    test("b2", std::vector<int>{14, 62, 46}, b2);
    test("b2b", std::vector<int>{53, 56, 55}, b2b);
    test("b3", std::vector<int>{45, 33, 41, 37}, b3);
    test("b4", std::vector<std::vector<int>>{{21, 22, 23}, {37, 38, 39}, {53, 54, 55}}, b4);

    std::cout << "All tests passed." << std::endl;
    return 0;
}