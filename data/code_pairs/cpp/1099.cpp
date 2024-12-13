#include <cstdlib>
#include <iostream>
#include <string>

int executeCommand(const std::string& command) {
    return system(command.c_str());
}

int main() {
    int status;

    // Test 1: Command expected to succeed
    status = executeCommand("echo Hello");
    if (status == 0) {
        std::cout << "Test 1 Passed." << std::endl;
    } else {
        std::cout << "Test 1 Failed." << std::endl;
    }

    // Test 2: Command expected to fail (nonexistent command)
    status = executeCommand("false"); // `false` command will return a non-zero exit status on Unix-like systems
    if (status == 0) {
        std::cout << "Test 2 Failed." << std::endl;
    } else {
        std::cout << "Test 2 Passed." << std::endl;
    }

    return 0;
}