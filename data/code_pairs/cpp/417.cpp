#include <iostream>
#include <memory>

class T {
public:
    int dummy = 0;
};

class Main {
public:
    void run() {
        T b; // Stack allocation
        b.dummy = 5;
        T* a = &b; // Pointer
        std::unique_ptr<T> c(new T); // Smart pointer for dynamic allocation

        sub(a);

        if (a == nullptr) {
            std::cout << "Test passed: a is nullptr." << std::endl;
        } else {
            std::cout << "Test failed: a is not nullptr." << std::endl;
        }
    }

private:
    void sub(T*& a) {
        a = nullptr;
        std::cout << "Subroutine SUB was called." << std::endl;
    }
};

int main() {
    Main program;
    program.run();
    return 0;
}