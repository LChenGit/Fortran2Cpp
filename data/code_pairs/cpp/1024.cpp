#include <cstdlib>

void return_and_stop(int n) {
    if (n == 0) {
        return;
    }
    std::exit(EXIT_FAILURE);
}