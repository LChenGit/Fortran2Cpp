#include <cstdint>

extern "C" {
    int32_t my_global_var = 0;

    void my_f90_sub() {
        my_global_var += 10;
    }
}