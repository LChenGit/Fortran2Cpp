#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>

int main() {
    const char* filename = "tmpfile";
    std::ofstream file;

    // Open the file in write mode (equivalent to Fortran open with status='new')
    file.open(filename, std::ios::out);
    if (!file) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Simulate the Fortran behavior of 'pad=yes' with 'yes' being initialized to 'no'
    // Note: In this context, C++ does not directly use padding as Fortran does. This is for alignment with the Fortran behavior.
    bool pad = false; // Equivalent of 'no' in Fortran

    // Convert boolean pad flag to string 'YES' or 'NO' for printing
    char a[4]; // 3 characters + null terminator
    std::strcpy(a, pad ? "YES" : "NO");

    // Print the value of 'a'
    std::cout << "C++: Pad: " << a << std::endl;

    // Assert the value of 'a' to ensure it's correct
    assert(std::strcmp(a, "NO") == 0);

    // Close the file and delete it (equivalent to Fortran close with status='delete')
    file.close();
    std::remove(filename);

    return 0;
}