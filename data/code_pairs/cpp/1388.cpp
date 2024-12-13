// bind_c_array_params.cpp
#include <iostream>
#include <cstddef> // for size_t
#include <cstdint> // for int32_t

extern "C" {
    void sub0(const int32_t* assumed_array, size_t size) {
        std::cout << "Assumed-size array elements:" << std::endl;
        for (size_t i = 0; i < size; ++i) {
            std::cout << assumed_array[i] << " ";
        }
        std::cout << std::endl;
    }

    void sub1(const int32_t* deferred_array, size_t size) {
        std::cout << "Deferred-size array elements:" << std::endl;
        for (size_t i = 0; i < size; ++i) {
            std::cout << deferred_array[i] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Test for sub0: Assuming size is known
    int32_t assumed_array[] = {1, 2, 3, 4, 5};
    size_t assumed_size = sizeof(assumed_array) / sizeof(assumed_array[0]);
    sub0(assumed_array, assumed_size);

    // Test for sub1: Deferred size array
    int32_t deferred_array[] = {10, 20, 30};
    size_t deferred_size = sizeof(deferred_array) / sizeof(deferred_array[0]);
    sub1(deferred_array, deferred_size);

    return 0;
}