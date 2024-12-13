#include <iostream>
#include <vector>
#include <cmath>

// Placeholder for the gaus_dist function
float gaus_dist(float r) {
    return std::exp(-r * r);  // Simple Gaussian distribution for test purposes
}

// GP structure
struct GP {
    int num_life;
    std::vector<float> alpha;
    float t;
    std::vector<float> tau;
    float R0;
};

// Global variable gp
GP gp;

float gaus_decay(float r) {
    float decay = 0.0f;
    for (int j = 0; j < gp.num_life; j++) {
        decay += gp.alpha[j] * std::exp(-gp.t / gp.tau[j] * (1.0f + std::pow(gp.R0 / r, 6.0f)));
    }
    float gaus = gaus_dist(r);
    return gaus * decay;
}

int main() {
    // Initialize test values
    gp.num_life = 2;
    gp.alpha = {0.5f, 1.0f};
    gp.t = 1.0f;
    gp.tau = {2.0f, 3.0f};
    gp.R0 = 1.0f;

    float r = 2.0f;
    float result = gaus_decay(r);

    std::cout << "Result: " << result << std::endl;
    return 0;
}