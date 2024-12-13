#include <iostream>
#include <vector>
#include <cassert>

void compute(std::vector<int>& arr) {
    const int size = 32 * 32 * 32;
    int i, j, k;
    int x;
    int* p;

    for (i = 0; i < size; i++) {
        arr[i] = i;
    }

    #pragma acc kernels copy(arr[0:size])
    for (i = 0; i < 32; i++) {
        for (j = 0; j < 32; j++) {
            p = &x;
            x = i ^ (j * 3);

            for (k = 0; k < 32; k++) {
                arr[i * 1024 + j * 32 + k] += x * k;
            }

            *p = i | (j * 5);

            for (k = 0; k < 32; k++) {
                arr[i * 1024 + j * 32 + k] += x * k;
            }
        }
    }
}

int main() {
    const int size = 32 * 32 * 32;
    std::vector<int> arr(size);
    compute(arr);

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            for (int k = 0; k < 32; k++) {
                int idx = i * 1024 + j * 32 + k;
                assert(arr[idx] == idx + (i ^ (j * 3)) * k + (i | (j * 5)) * k);
            }
        }
    }

    std::cout << "All tests passed!" << std::endl;
    return 0;
}