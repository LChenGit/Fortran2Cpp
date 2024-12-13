// mod_pdf.h
#include <cmath>
#include <random>

class mod_pdf {
private:
    static std::mt19937_64 rng;
    static std::uniform_real_distribution<long double> dist;
    static bool have_second_sample;
    static long double saved_sample;

public:
    static long double randn_box_muller(long double mu, long double sigma);
    static long double norm_pdf(long double x, long double mean, long double variance);
};

// mod_pdf.cpp
#include "mod_pdf.h"

std::mt19937_64 mod_pdf::rng(std::random_device{}());
std::uniform_real_distribution<long double> mod_pdf::dist(0.0L, 1.0L);
bool mod_pdf::have_second_sample = false;
long double mod_pdf::saved_sample = 0.0L;

long double mod_pdf::randn_box_muller(long double mu, long double sigma) {
    if (!have_second_sample) {
        long double myrand1, myrand2, v1, v2, rsq, fac;
        do {
            myrand1 = dist(rng);
            myrand2 = dist(rng);
            v1 = 2.0L * myrand1 - 1.0L;
            v2 = 2.0L * myrand2 - 1.0L;
            rsq = v1 * v1 + v2 * v2;
        } while (rsq >= 1.0L || rsq == 0.0L);

        fac = std::sqrt(-2.0L * std::log(rsq) / rsq);
        saved_sample = v1 * fac * sigma + mu;
        have_second_sample = true;
        return v2 * fac * sigma + mu;
    } else {
        have_second_sample = false;
        return saved_sample;
    }
}

long double mod_pdf::norm_pdf(long double x, long double mean, long double variance) {
    return 1.0L / (std::sqrt(variance * 2.0L * 3.14159265358979323846L)) * std::exp(-std::pow(x - mean, 2) / (2.0L * variance));
}