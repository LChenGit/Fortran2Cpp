#include <iostream>

class T {
public:
    int x;
    T() : x(0) {}
};

class T2 {
public:
    T* a;
    T2() : a(nullptr) {}
    T2(const T2& other) {
        if (other.a != nullptr) {
            a = new T();
            *a = *(other.a);
        } else {
            a = nullptr;
        }
    }
    ~T2() { delete a; }
    T2& operator=(const T2& other) {
        if (this != &other) {
            delete a;
            if (other.a != nullptr) {
                a = new T();
                *a = *(other.a);
            } else {
                a = nullptr;
            }
        }
        return *this;
    }
};

void test2() {
    T2 one, two;

    two.a = new T();
    one = two;
}

void test_unit() {
    T2 test_obj;
    test_obj.a = new T();
    test_obj.a->x = 5;

    if (test_obj.a->x == 5) {
        std::cout << "C++ Test Passed" << std::endl;
    } else {
        std::cout << "C++ Test Failed" << std::endl;
    }
}

int main() {
    test2();
    test_unit();
    return 0;
}