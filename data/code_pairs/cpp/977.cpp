#include <iostream>
#include <cassert>

class aqq_m {
public:
    class aqq_t {
    public:
        bool initialized;

        aqq_t() : initialized(false) {
            aqq_init();
        }

        void aqq_init() {
            initialized = true;
            std::cout << "aqq_t initialized.\n"; 
        }
    };
};

int main() {
    aqq_m::aqq_t aqq;
    assert(aqq.initialized == true); 
    std::cout << "Test passed: aqq_t is initialized.\n";
    return 0;
}