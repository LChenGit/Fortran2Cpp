#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

void quicksort(std::vector<double>& a, int lo, int hi) {
    if (lo >= hi) return;
    int i = lo, j = hi;
    double pivot = a[(lo + hi) / 2];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            std::swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (lo < j) quicksort(a, lo, j);
    if (i < hi) quicksort(a, i, hi);
}

void test_quicksort() {
    std::vector<double> test_array = {3.0, 1.0, 4.0, 1.5, 2.0};
    std::vector<double> expected_array = {1.0, 1.5, 2.0, 3.0, 4.0};

    // Call the quicksort function
    quicksort(test_array, 0, test_array.size() - 1);

    // Check if the sorted array matches the expected array
    assert(test_array == expected_array);

    std::cout << "Quicksort test passed." << std::endl;
}

int main() {
    test_quicksort();
    return 0;
}