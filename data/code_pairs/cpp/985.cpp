#include <iostream>

class tens_signature_t {
public:
    ~tens_signature_t() {
        std::cout << "tens_signature_t destructor called" << std::endl;
    }
};

class tens_header_t {
public:
    tens_signature_t signature;

    ~tens_header_t() {
        std::cout << "tens_header_t destructor called" << std::endl;
    }
};

int main() {
    std::cout << "Creating and destroying a tens_header_t object" << std::endl;
    {
        tens_header_t header;
    } // header goes out of scope here, triggering destructors
    return 0;
}