#include <iostream>
#include <vector>

void ynorm(int maxsiz, int jstrt, int jfins, std::vector<double>& observ, double rnorm) {
    // Note: Adjust jstrt and jfins for 0-based indexing inside the function if needed.
    for (int i_res = jstrt - 1; i_res < jfins; ++i_res) {
        observ[i_res] = rnorm * observ[i_res];
    }
}

int main() {
    const int maxsiz = 10;
    std::vector<double> observ(maxsiz);
    double rnorm = 2.0;
    int jstrt = 2; // No adjustment needed here, handled in the function.
    int jfins = 5;

    // Populate the observ array with initial values
    for (int i = 0; i < maxsiz; ++i) {
        observ[i] = static_cast<double>(i + 1);
    }

    // Call the ynorm function
    ynorm(maxsiz, jstrt, jfins, observ, rnorm);

    // Print the results to verify the computation
    std::cout << "Observ array after calling ynorm:" << std::endl;
    for (auto val : observ) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}