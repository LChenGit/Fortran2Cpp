#include <vector>
#include <numeric>  // std::accumulate
#include <cassert>  // assert for simple testing
#include <iostream> // std::cout

struct T {
    std::vector<int> v;
};

class A {
public:
    static int n;

    static int FOO() {
        T var;
        var.v.resize(n);
        
        for(int i = 0; i < n; ++i) {
            var.v[i] = i + 1;
        }
        
        int suma = std::accumulate(var.v.begin(), var.v.end(), 0);
        return suma;
    }
};

int A::n = 0;

int main() {
    A::n = 5;
    int result = A::FOO();
    
    assert(result == 15);
    std::cout << "C++ Test Passed: Sum is " << result << std::endl;
    
    return 0;
}