#include <iostream>
#include <cassert>

class t {
public:
    float i;
private:
    float k = 2.0f;
  
    // Note: Made this public to match the Fortran test; originally private in the translation.
    // Adjusted visibility to ensure consistency with Fortran's testing approach.
public:
    void p1(int& ret1) {
        ret1 = static_cast<int>(i + k);
    }

    t() : i(0) {}

    static int func1(int para1) {
        return para1 * 2;
    }
};

void test_t() {
    t obj;
    int result;
    obj.i = 3.0f;
    obj.p1(result); // Directly calling p1 to match Fortran's test scenario
    std::cout << "Test p1 with i=3.0 and k=2.0, expected result 5, got " << result << std::endl;
    assert(result == 5);

    int testFunc1 = t::func1(5);
    std::cout << "Test func1 with para1=5, expected result 10, got " << testFunc1 << std::endl;
    assert(testFunc1 == 10);
}

int main() {
    test_t();
    std::cout << "All tests passed." << std::endl;
    return 0;
}