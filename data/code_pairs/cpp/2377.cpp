#include <iostream>
#include <iomanip>
#include <limits>

namespace performance {
    void perf_header() {
        std::cout << std::endl;
        std::cout << "        # Photons    CPU time (sec)    Photons/sec  " << std::endl;
        std::cout << "      ----------------------------------------------" << std::endl;
    }

    void perf_footer() {
        std::cout << "      ----------------------------------------------" << std::endl;
        std::cout << std::endl;
    }

    void perf_numbers(int count, double time) {
        std::cout << " ";
        if (time <= 0.0) {
            std::cout << std::setw(12) << count 
                      << std::setw(8) << std::fixed << std::setprecision(1) << time 
                      << "       ...   " << std::endl;
        } else {
            std::cout << std::setw(12) << count 
                      << std::setw(8) << std::fixed << std::setprecision(1) << time 
                      << std::setw(12) << std::fixed << std::setprecision(2) << count / time << std::endl;
        }
    }
}

int main() {
    performance::perf_header();
    performance::perf_numbers(1000000, 123.4);
    performance::perf_numbers(500000, 0.0);
    performance::perf_footer();
    return 0;
}