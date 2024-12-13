#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

class CArrays {
public:
    static double array_in(const std::vector<double>& x) {
        return std::accumulate(x.begin(), x.end(), 0.0);
    }

    static double array_in_2(const std::vector<double>& x) {
        double sum = 0.0;
        for (int i = 0; i < std::min(4, static_cast<int>(x.size())); ++i) {
            sum += x[i];
        }
        return sum;
    }

    static void array_out(std::vector<double>& x, std::vector<double>& y) {
        std::fill(x.begin(), x.end(), 20.0);
        std::fill(y.begin(), y.end(), 30.0);
    }

    static double inner_prod(const std::vector<double>& a, const std::vector<double>& b) {
        if (a.size() != b.size()) {
            std::cerr << "Arrays must be of the same size" << std::endl;
            return 0.0;
        }
        double sum = 0.0;
        for (size_t i = 0; i < a.size(); ++i) {
            sum += a[i] * b[i];
        }
        return sum;
    }
};