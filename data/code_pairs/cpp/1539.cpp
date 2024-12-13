#include <random>
#include <vector>
#include <cmath>

class ProbabilityDistributions {
public:
    ProbabilityDistributions() {
        rand_engine.seed(std::random_device{}());
    }

    double generateNormalBoxMuller() {
        std::uniform_real_distribution<double> uniform_distribution(0.0, 1.0);
        double u1 = uniform_distribution(rand_engine);
        double u2 = uniform_distribution(rand_engine);
        return sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    }

private:
    std::mt19937 rand_engine;
};