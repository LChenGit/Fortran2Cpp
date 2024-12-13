#include <iostream>
using namespace std;

class t1 {
public:
    int a1;
    t1() : a1(1) {} // Constructor to initialize a1
};

class t2 : public t1 {
public:
    int a2;
    t2() : a2(2) {} // Constructor to initialize a2
};

class t3 : public t2 {
public:
    int a3;
    t3() : a3(3) {} // Constructor to initialize a3
};

void test(const char* testName, int expected, int actual) {
    cout << testName << ": " << (expected == actual ? "PASS" : "FAIL") << endl;
}

int main() {
    t3 x3;
    int i;

    i = x3.a2;
    test("x3.a2", 2, i);
    
    i = x3.a1;
    test("x3.a1", 1, i);

    return 0;
}