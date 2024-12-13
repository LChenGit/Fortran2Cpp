#include <cmath>

class PolyEos {
public:
    double K, gamma;
    double rho, e;
    double drho_dp, de_dp;
    double p;

    PolyEos() : K(0.0), gamma(0.0), rho(0.0), e(0.0), drho_dp(0.0), de_dp(0.0), p(0.0) {}

    void eos_init(double K, double gamma) {
        this->K = K;
        this->gamma = gamma;
    }

    void eos_p(double pres) {
        this->p = pres;
        this->rho = std::pow(this->p / this->K, 1.0 / this->gamma);
        eos_compute();
    }

    void eos_rho(double dens) {
        this->rho = dens;
        this->p = this->K * std::pow(this->rho, this->gamma);
        eos_compute();
    }

private:
    void eos_compute() {
        this->e = (this->p / this->rho) / (this->gamma - 1.0);
        this->drho_dp = (1.0 / (this->K * this->gamma)) * std::pow(this->rho, 1.0 - this->gamma);
        this->de_dp = (-this->p / (this->gamma - 1.0) / (this->rho * this->rho)) * this->drho_dp +
                      (1.0 / this->rho / (this->gamma - 1.0));
    }
};