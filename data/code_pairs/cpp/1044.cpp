#include <iostream>
#include <vector>
#include <cmath>
#include <optional>

void PlSchmidt(std::vector<double>& p, int lmax, double z, std::optional<int>& exitstatus) {
    if (exitstatus) *exitstatus = 0;

    if (p.size() < static_cast<size_t>(lmax + 1)) {
        std::cerr << "Error --- PlSchmidt" << std::endl;
        std::cerr << "P must be dimensioned as (LMAX+1) where LMAX is " << lmax << std::endl;
        std::cerr << "Input array is dimensioned " << p.size() << std::endl;
        if (exitstatus) {
            *exitstatus = 1;
            return;
        } else {
            exit(1);
        }
    }

    if (lmax < 0) {
        std::cerr << "Error --- PlSchmidt" << std::endl;
        std::cerr << "LMAX must be greater than or equal to 0." << std::endl;
        std::cerr << "Input value is " << lmax << std::endl;
        if (exitstatus) {
            *exitstatus = 2;
            return;
        } else {
            exit(1);
        }
    } else if (std::abs(z) > 1.0) {
        std::cerr << "Error --- PlSchmidt" << std::endl;
        std::cerr << "ABS(Z) must be less than or equal to 1." << std::endl;
        std::cerr << "Input value is " << z << std::endl;
        if (exitstatus) {
            *exitstatus = 3;
            return;
        } else {
            exit(1);
        }
    }

    double pm2 = 1.0;
    p[0] = 1.0;

    if (lmax > 0) {
        double pm1 = z;
        p[1] = pm1;

        for (int l = 2; l <= lmax; ++l) {
            double pl = ((2 * l - 1) * z * pm1 - (l - 1) * pm2) / static_cast<double>(l);
            p[l] = pl;
            pm2 = pm1;
            pm1 = pl;
        }
    }
}

int main() {
    int lmax = 4;
    double z = 0.5;
    std::vector<double> p(lmax + 1);
    std::optional<int> exitstatus;

    PlSchmidt(p, lmax, z, exitstatus);

    if (exitstatus && *exitstatus != 0) {
        std::cerr << "An error occurred with code: " << *exitstatus << std::endl;
        return *exitstatus;
    }

    std::cout << "Testing PlSchmidt with lmax = " << lmax << " and z = " << z << std::endl;
    for (int i = 0; i <= lmax; ++i) {
        std::cout << "P[" << i << "] = " << p[i] << std::endl;
    }

    return 0;
}