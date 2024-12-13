#include <iostream>
#include <cstdlib> // For std::abort()

// Function prototypes
double add(double x, double y);
bool greater(double x, double y);

// Test function prototypes
void test_add();
void test_greater();
void test_procedure_pointer();

int main() {
    // Main program logic tests omitted for brevity

    // Unit tests
    test_add();
    test_greater();
    test_procedure_pointer();

    return 0;
}

double add(double x, double y) {
    return x + y;
}

bool greater(double x, double y) {
    return x > y;
}

void test_add() {
    if (add(2, 3) != 5) std::abort();
    std::cout << "test_add passed." << std::endl;
}

void test_greater() {
    if (!greater(5, 3)) std::abort();
    if (greater(2, 3)) std::abort();
    std::cout << "test_greater passed." << std::endl;
}

void test_procedure_pointer() {
    double (*f_test)(double, double);
    bool g_test;

    f_test = add;
    g_test = greater(4., f_test(1., 2.));
    if (!g_test) std::abort();
    std::cout << "test_procedure_pointer passed." << std::endl;
}