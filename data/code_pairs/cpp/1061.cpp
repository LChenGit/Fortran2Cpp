#include <iostream>
#include <cstdlib>

void sub(int y);
void sub2(void* arg);
void abortIfNotEqual(int lhs, int rhs);

int sum = 0;

struct t {
    int i = 0;
    void (*ppc)(int) = nullptr;
    void (*proc)(void*) = nullptr;
};

struct t2 : public t {
    void (*proc2)(int) = nullptr;
};

void sub(int y) {
    sum += y;
}

void sub2(void* arg) {
    t* obj = static_cast<t*>(arg);
    obj->i += sum;
}

void abortIfNotEqual(int lhs, int rhs) {
    if (lhs != rhs) {
        std::cerr << "Assertion failed";
        std::exit(1);
    }
}

void test() {
    t test_x;
    t2 test_x2;

    sum = 0;

    test_x.i = 10;
    test_x.ppc = sub;
    test_x.ppc(5);
    abortIfNotEqual(sum, 5);

    test_x2.proc2 = sub;
    test_x2.proc2(5);
    abortIfNotEqual(sum, 10);

    test_x.proc = reinterpret_cast<void (*)(void*)>(sub2);
    test_x.proc(static_cast<void*>(&test_x));
    abortIfNotEqual(test_x.i, 20);

    std::cout << "All C++ tests passed." << std::endl;
}

int main() {
    test();
    return 0;
}