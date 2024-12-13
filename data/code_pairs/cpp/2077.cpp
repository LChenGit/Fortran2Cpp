#include <iostream>

int fact(int n) {
    if (n <= 1) return 1;
    else return n * fact(n - 1);
}

void test_fact(int test_value, int expected_value, const std::string& test_case_label) {
    int result = fact(test_value);
    if (result == expected_value) {
        std::cout << "PASS: " << test_case_label << std::endl;
    } else {
        std::cout << "FAIL: " << test_case_label 
                  << ". Expected: " << expected_value << ", Got: " << result << std::endl;
    }
}

int main() {
    // Test case 1: Fact(5)
    test_fact(5, 120, "Fact(5)");

    // Test case 2: Fact(0)
    test_fact(0, 1, "Fact(0)");

    // Add more test cases as needed

    return 0;
}