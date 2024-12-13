#include <iostream>
#include <array>

class XLAENV {
public:
    void operator()(int ISPEC, int NVALUE);
    static int getIPARMSValue(int index); // Public method to access IPARMS values

private:
    static std::array<int, 100> IPARMS;
};

// Initialize the static member variable
std::array<int, 100> XLAENV::IPARMS = {0};

void XLAENV::operator()(int ISPEC, int NVALUE) {
    if (ISPEC >= 1 && ISPEC <= 9) {
        IPARMS[ISPEC - 1] = NVALUE; // Adjusted index for 0-based array in C++
    }
}

int XLAENV::getIPARMSValue(int index) {
    if (index >= 1 && index <= 100) {
        return IPARMS[index - 1]; // Adjusted index for 0-based array in C++
    } else {
        // Handle out-of-range index if necessary
        return -1; // Return an invalid value or handle it as per your need
    }
}

void printIPARMS(int index) {
    std::cout << "IPARMS(" << index << ") = " << XLAENV::getIPARMSValue(index) << std::endl;
}

int main() {
    XLAENV xlaenv;

    xlaenv(5, 10);
    printIPARMS(5);  // Should print 10

    xlaenv(3, 20);
    printIPARMS(3);  // Should print 20

    xlaenv(10, 30);
    printIPARMS(10);  // Should print 0 (since ISPEC is out of range and index 10 is not set)

    return 0;
}