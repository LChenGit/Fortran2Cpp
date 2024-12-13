#ifndef MAXVALFUNCTIONS_H
#define MAXVALFUNCTIONS_H

#include <vector>
#include <algorithm>

void maxvalIJS2(const std::vector<int>& array, int& maxValue) {
    if (!array.empty()) {
        maxValue = *std::max_element(array.begin(), array.end());
    } else {
        maxValue = 0;
    }
}

void maxvalISS2(const std::vector<int>& array, int& maxValue) {
    if (!array.empty()) {
        maxValue = *std::max_element(array.begin(), array.end());
    } else {
        maxValue = 0;
    }
}

#endif // MAXVALFUNCTIONS_H