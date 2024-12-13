#include <vector>
#include <iostream>

template<typename T>
void interchangeSortDecReal(std::vector<T>& vec) {
    int n = vec.size();
    T swapValue;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (vec[i] < vec[j]) {
                swapValue = vec[i];
                vec[i] = vec[j];
                vec[j] = swapValue;
            }
        }
    }
}