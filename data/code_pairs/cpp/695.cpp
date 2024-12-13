#include <iostream>
#include <algorithm> // For std::min and std::max

void qqqmima(const float* fld, int n, float& xmin, float& xmax) {
    float xxmin = fld[0];
    float xxmax = fld[0];

    for (int i = 1; i < n; ++i) {
        xxmin = std::min(fld[i], xxmin);
        xxmax = std::max(fld[i], xxmax);
    }

    xmin = xxmin;
    xmax = xxmax;
}

int main() {
    float fld[] = {1.0f, 3.5f, -2.0f, 4.5f, 0.0f};
    int n = sizeof(fld) / sizeof(fld[0]);
    float xmin, xmax;

    qqqmima(fld, n, xmin, xmax);

    std::cout << "The minimum value is: " << xmin << std::endl;
    std::cout << "The maximum value is: " << xmax << std::endl;

    return 0;
}