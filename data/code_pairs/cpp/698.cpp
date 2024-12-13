#include <cstdlib>
#include <iostream>
#include <cassert>

void setEnvironmentVariables() {
    // Setting environment variables
    setenv("UVM_TESTNAME", "uex_ve_multicore_test", 1);
    setenv("SW_TESTNAME", "UEX.basic_multicore_test", 1);
}

void checkEnvironmentVariable(const char* name, const char* expectedValue) {
    char* value = std::getenv(name);
    assert(value != nullptr && "Environment variable not found.");
    assert(std::string(value) == std::string(expectedValue) && "Environment variable has an unexpected value.");
    std::cout << name << " is set correctly." << std::endl;
}

int main() {
    setEnvironmentVariables();
    checkEnvironmentVariable("UVM_TESTNAME", "uex_ve_multicore_test");
    checkEnvironmentVariable("SW_TESTNAME", "UEX.basic_multicore_test");
    return 0;
}