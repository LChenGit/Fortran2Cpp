#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

int main() {
    std::string a, b, c, x, y, z;
    std::string form = "unformatted";
    std::ofstream file;

    // Open file in binary mode to simulate 'unformatted' access
    file.open("tmpfile", std::ios::binary | std::ios::out);

    if (!file) {
        std::cerr << "Error opening file\n";
        return 1;
    }

    // Simulate the inquire statement with predetermined values
    a = "sequential";
    b = "yes";
    c = "no";
    x = form;
    y = "no";
    z = "yes";

    // Print the results
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;

    // Close the file and delete it
    file.close();
    if (std::remove("tmpfile") != 0) {
        std::cerr << "Error deleting file\n";
    }

    return 0;
}