#include <iostream>
#include <string>

// Assuming namespace plugin_flags is required for some context
namespace plugin_flags {
    // Any necessary declarations go here
}

// Function definition
void plugin_clean(const std::string& prog, bool lflag) {
    std::cout << "Program: " << prog << std::endl;
    std::cout << "Flag: " << std::boolalpha << lflag << std::endl;
}

// Main function for testing
int main() {
    plugin_clean("TestProgram", true);
    plugin_clean("AnotherTest", false);
    return 0;
}