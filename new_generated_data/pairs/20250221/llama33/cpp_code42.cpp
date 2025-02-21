#include <iostream>
#include <cmath>

void entropy(double* f, double temp, int n, double& ent) {
    ent = 0.0;
    for (int i = 0; i < n; i++) {
        if (f[i] > 0) {
            ent -= f[i] * log(f[i]);
        }
    }
    ent /= temp;
}

bool has_close_elements(double* arr, int n, double tol) {
    bool result = true;
    for (int i = 0; i < n - 1; i++) {
        if (std::abs(arr[i] - arr[i + 1]) > tol) {
            result = false;
            break;
        }
    }
    return result;
}

void test_entropy() {
    double f[] = {0.2, 0.4, 0.6, 0.8};
    double temp = 5.0;
    int n = sizeof(f) / sizeof(f[0]);
    double ent;

    entropy(f, temp, n, ent);
    std::cout << "Entropy: " << ent << std::endl;
}

void test_has_close_elements() {
    double close_arr[] = {1.0, 1.01, 1.02};
    double not_close_arr[] = {1.0, 2.0, 3.0};

    if (!has_close_elements(close_arr, sizeof(close_arr) / sizeof(close_arr[0]), 0.1)) {
        std::cout << "Test failed: close_arr does not have close elements" << std::endl;
    } else {
        std::cout << "Test passed: close_arr has close elements" << std::endl;
    }

    if (has_close_elements(not_close_arr, sizeof(not_close_arr) / sizeof(not_close_arr[0]), 0.1)) {
        std::cout << "Test failed: not_close_arr has close elements" << std::endl;
    } else {
        std::cout << "Test passed: not_close_arr does not have close elements" << std::endl;
    }
}

int main() {
    test_entropy();
    test_has_close_elements();
    return 0;
}