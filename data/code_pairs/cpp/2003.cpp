// sum_array.cpp
#include <iostream>
#include <vector>
using namespace std;

int sumArray(const vector<int>& arr) {
    int total = 0;
    for (int num : arr) {
        total += num;
    }
    return total;
}