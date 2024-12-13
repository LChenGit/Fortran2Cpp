#include <iostream>
#include <cmath>

void sla_DVN(const double V[3], double UV[3], double &VM) {
    double W1 = 0.0;

    // Compute the magnitude of the vector V
    for(int i = 0; i < 3; ++i) {
        double W2 = V[i];
        W1 += W2 * W2;
    }

    W1 = std::sqrt(W1);
    VM = W1;

    // Avoid division by zero
    if (W1 <= 0.0) {
        W1 = 1.0;
    }

    // Normalize the vector
    for(int i = 0; i < 3; ++i) {
        UV[i] = V[i] / W1;
    }
}

// Function to print vectors
void print_vector(const char* label, const double vec[3]) {
    std::cout << label << ": ["
              << vec[0] << ", "
              << vec[1] << ", "
              << vec[2] << "]" << std::endl;
}

int main() {
    double V[3], UV[3], VM;

    // Test case 1
    V[0] = 1.0;
    V[1] = 0.0;
    V[2] = 0.0;

    sla_DVN(V, UV, VM);

    std::cout << "Test Case 1:" << std::endl;
    print_vector("Input Vector", V);
    print_vector("Unit Vector", UV);
    std::cout << "Magnitude: " << VM << std::endl;

    // Test case 2
    V[0] = 3.0;
    V[1] = 4.0;
    V[2] = 0.0;

    sla_DVN(V, UV, VM);

    std::cout << "Test Case 2:" << std::endl;
    print_vector("Input Vector", V);
    print_vector("Unit Vector", UV);
    std::cout << "Magnitude: " << VM << std::endl;

    return 0;
}