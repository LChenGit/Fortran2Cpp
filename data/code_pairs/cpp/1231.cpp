#include <iostream>
#include <string>
#include <cctype> // For std::toupper and std::tolower

void xxcase(const std::string& input, std::string& output, const std::string& type) {
    output = input; // Copy input to output

    if (type == "UC" || type == "uc") {
        for (char &c : output) c = std::toupper(c);
    } else if (type == "LC" || type == "lc") {
        for (char &c : output) c = std::tolower(c);
    }
}

int main() {
    std::string input, output, type;

    // Test 1: Convert to uppercase
    input = "hello, world!";
    type = "UC";
    xxcase(input, output, type);
    std::cout << "UC: " << output << std::endl;

    // Test 2: Convert to lowercase
    input = "HELLO, WORLD!";
    type = "LC";
    xxcase(input, output, type);
    std::cout << "LC: " << output << std::endl;

    // Test 3: Mixed case to uppercase
    input = "Hello, World!";
    type = "UC";
    xxcase(input, output, type);
    std::cout << "uc: " << output << std::endl;

    // Test 4: Mixed case to lowercase
    input = "Hello, World!";
    type = "LC";
    xxcase(input, output, type);
    std::cout << "lc: " << output << std::endl;

    return 0;
}