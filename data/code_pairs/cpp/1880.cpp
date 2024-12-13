#include <iostream>
#include <string>

namespace mp_global {
    void mp_startup() {
        std::cout << "MPI startup procedure called." << std::endl;
    }
}

namespace environment {
    void start(const std::string& code) {
        std::cout << "Environment start procedure called with code: " << code << std::endl;
    }
}

void start_bse() {
    std::string code = "BSE";

#ifdef __MPI
    mp_global::mp_startup();
#endif

    environment::start(code);
}

int main() {
    start_bse();
    return 0;
}