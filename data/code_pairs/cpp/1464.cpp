#include <iostream>
#include <cstring> // For strlen

class Chanel_C {
public:
    static const int filename_len = 240;
    int iw = 26;
    char job_fn[filename_len] = "";
    char output_fn[filename_len] = "";
    char restart_fn[filename_len] = "";
    char density_fn[filename_len] = "";
    char log_fn[filename_len] = "";
    char end_fn[filename_len] = "";
    char ext_fn[filename_len] = "";
    char archive_fn[filename_len] = "";
    int ifilen[145] = {0};
    int ioda[145] = {0}; // Assuming similar initialization
    int irecln = 1023;
    int irecst = 0; // Assuming a default value

    Chanel_C() {
        // Initialization if needed
    }
};

int main() {
    Chanel_C testObj;

    std::cout << "Testing integer variables..." << std::endl;
    if (testObj.iw == 26) {
        std::cout << "PASS: iw is initialized correctly." << std::endl;
    } else {
        std::cout << "FAIL: iw is not initialized correctly." << std::endl;
    }

    std::cout << "Testing character variables..." << std::endl;
    if (strlen(testObj.job_fn) == 0) {
        std::cout << "PASS: job_fn is initialized correctly." << std::endl;
    } else {
        std::cout << "FAIL: job_fn is not initialized correctly." << std::endl;
    }

    std::cout << "Testing integer arrays..." << std::endl;
    if (testObj.ifilen[0] == 0) {
        std::cout << "PASS: ifilen is initialized correctly." << std::endl;
    } else {
        std::cout << "FAIL: ifilen is not initialized correctly." << std::endl;
    }

    return 0;
}