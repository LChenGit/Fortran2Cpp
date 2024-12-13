#include <vector>
#include <iostream>

template<typename T>
std::vector<std::vector<std::vector<T>>> create3DVector(int x, int y, int z, T value) {
    return std::vector<std::vector<std::vector<T>>>(x, std::vector<std::vector<T>>(y, std::vector<T>(z, value)));
}

template<typename T>
std::vector<std::vector<T>> create2DVector(int x, int y, T value) {
    return std::vector<std::vector<T>>(x, std::vector<T>(y, value));
}

void foo(std::vector<std::vector<int>>& array1, std::vector<std::vector<std::vector<float>>>& array2) {
    for (auto& row : array1) {
        for (auto& elem : row) {
            elem = 5;
        }
    }
    array1[0][0] = 30;

    for (auto& depth : array2) {
        for (auto& row : depth) {
            for (auto& elem : row) {
                elem = 3.0f;
            }
        }
    }
    array2[0][0][0] = 30.0f;
    array2[2][2][2] = 90.0f;
}