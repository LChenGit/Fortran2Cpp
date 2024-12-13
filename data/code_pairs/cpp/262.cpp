#include <cstdlib>
#include <iostream>

void a1() {
    std::exit(-666); // Adjusted for the limits of exit codes if necessary
}

void a2() {
    std::exit(-666); // Adjusted for the limits of exit codes if necessary
}

void a3() {
    std::exit(123456 % 256); // Adjusting exit code to fit into the 0-255 range
}

void a4() {
    std::exit(123456 % 256); // Adjusting exit code to fit into the 0-255 range
}

void a5() {
    std::exit(true ? 667 : 668); // Using the ternary operator as a substitute for Fortran's merge
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <test_number>" << std::endl;
        return 1; // Using 1 for error indication
    }

    int test_number = std::stoi(argv[1]);

    switch (test_number) {
    case 1:
        a1();
        break;
    case 2:
        a2();
        break;
    case 3:
        a3();
        break;
    case 4:
        a4();
        break;
    case 5:
        a5();
        break;
    default:
        std::cerr << "Invalid test number" << std::endl;
        return 1; // Using 1 for error indication
    }

    return 0; // This will never be reached due to std::exit calls
}