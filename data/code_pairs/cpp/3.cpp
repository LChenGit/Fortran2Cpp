#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
#include <cmath> // For std::fabs

void smooth_bruckner(const std::vector<double>& y, std::vector<double>& y_bkg, int n, int smooth_points, int iterations) {
    std::vector<double> y_extended(n + 2 * smooth_points);
    double window_avg;
    double y_new;
    double window_size = 2 * smooth_points + 1;

    // Initialize y_extended
    std::fill(y_extended.begin(), y_extended.begin() + smooth_points, y[0]);
    std::copy(y.begin(), y.end(), y_extended.begin() + smooth_points);
    std::fill(y_extended.begin() + smooth_points + n, y_extended.end(), y[n-1]);

    for (int j = 0; j < iterations; ++j) {
        window_avg = std::accumulate(y_extended.begin(), y_extended.begin() + 2 * smooth_points + 1, 0.0) / window_size;
        for (int i = smooth_points; i <= n + smooth_points - 1; ++i) {
            if (y_extended[i] > window_avg) {
                y_new = window_avg;
                window_avg += ((window_avg - y_extended[i]) + (y_extended[i + smooth_points + 1] - y_extended[i - smooth_points])) / window_size;
                y_extended[i] = y_new;
            } else {
                window_avg += (y_extended[i + smooth_points + 1] - y_extended[i - smooth_points]) / window_size;
            }
        }
    }

    // Copy the relevant part of y_extended back into y_bkg
    std::copy(y_extended.begin() + smooth_points, y_extended.begin() + smooth_points + n, y_bkg.begin());
}

int main() {
    int n = 10; // Example size of y
    int smooth_points = 2; // Example smooth points
    int iterations = 3; // Example iterations
    std::vector<double> y = {1, 2, 3, 4, 5, 4, 3, 2, 1, 0}; // Example input
    std::vector<double> y_bkg(n); // Output vector

    smooth_bruckner(y, y_bkg, n, smooth_points, iterations);

    // Print the result
    std::cout << "y_bkg: ";
    for (auto val : y_bkg) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}