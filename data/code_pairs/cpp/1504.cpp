#ifndef RANDOM_H
#define RANDOM_H

#include <vector>
#include <random>

class Random {
public:
    Random();
    void init_random_seed();
    void set_random_seed(unsigned int seed_offset);
    double rand_uniform();
    int rand_int(int lo, int up);
    std::vector<double> rand_vec(int n);
    double randc(double x0, double gamma);
    double randn(double mean, double std);
    std::vector<double> randn_vec(int n);

private:
    std::default_random_engine engine;
};

#endif