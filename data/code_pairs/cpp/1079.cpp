#include <iostream>
#include <cassert>

class t {
private:
    int priv() {
        std::cout << "Private method called" << std::endl;
        return 1; // Indicating success
    }

public:
    int publ() {
        std::cout << "Public method called" << std::endl;
        return 0; // Indicating success
    }

    // Friend function declared for testing purposes
    friend void test_private_access(t& obj);
};

// Function to test private access
void test_private_access(t& obj) {
    assert(obj.priv() == 1);
}

void test_public_access() {
    t obj;
    assert(obj.publ() == 0);
}

int main() {
    t obj;
    test_public_access();
    test_private_access(obj);
    std::cout << "All tests passed!" << std::endl;
    return 0;
}