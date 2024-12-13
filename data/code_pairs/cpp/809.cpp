#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

class ModArrays {
public:
    static std::vector<float> reverse(const std::vector<float>& x) {
        std::vector<float> result(x.rbegin(), x.rend());
        return result;
    }

    static float average(const std::vector<float>& x) {
        float sum = std::accumulate(x.begin(), x.end(), 0.0f);
        return sum / x.size();
    }

    static float std(const std::vector<float>& x) {
        float avg = average(x);
        float sumSqDiff = std::accumulate(x.begin(), x.end(), 0.0f,
                                          [avg](float acc, float val) {
                                              return acc + (val - avg) * (val - avg);
                                          });
        return std::sqrt(sumSqDiff / x.size());
    }

    static std::vector<float> moving_average(const std::vector<float>& x, int window_size) {
        std::vector<float> ma(x.size());
        for (size_t i = 0; i < x.size(); ++i) {
            int lower_bound = std::max(static_cast<int>(i) - window_size + 1, 0);
            float avg = average(std::vector<float>(x.begin() + lower_bound, x.begin() + i + 1));
            ma[i] = avg;
        }
        return ma;
    }

    static std::vector<float> moving_std(const std::vector<float>& x, int window_size) {
        std::vector<float> ms(x.size());
        for (size_t i = 0; i < x.size(); ++i) {
            int lower_bound = std::max(static_cast<int>(i) - window_size + 1, 0);
            float standardDev = std(std::vector<float>(x.begin() + lower_bound, x.begin() + i + 1));
            ms[i] = standardDev;
        }
        return ms;
    }
};