#include <iostream>
#include <cmath>
#include <cassert>

void compute_nombre_dor(double& limite_suite, double& nombre_or) {
    const double epsilon = 1.e-5;
    double u_prec = 1.0, u_cour = 1.0;
    double v_prec, v_cour;
    double somme;

    nombre_or = (1.0 + std::sqrt(5.0)) / 2.0;

    while (true) {
        v_prec = u_cour / u_prec;
        somme = u_cour + u_prec;
        u_prec = u_cour;
        u_cour = somme;
        v_cour = u_cour / u_prec;

        if (std::abs((v_cour - v_prec) / v_prec) < epsilon) {
            break;
        }
    }

    limite_suite = v_cour;
}

void test_nombre_dor() {
    double expected_nombre_or = (1.0 + std::sqrt(5.0)) / 2.0;
    double computed_nombre_or, computed_limite_suite;
    
    compute_nombre_dor(computed_limite_suite, computed_nombre_or);

    assert(std::abs(computed_nombre_or - expected_nombre_or) < 1.e-5 && "Nombre d'or is incorrect");
    assert(std::abs(computed_limite_suite - expected_nombre_or) < 1.e-5 && "Limite de la suite (vn) is incorrect");

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test_nombre_dor();
    return 0;
}