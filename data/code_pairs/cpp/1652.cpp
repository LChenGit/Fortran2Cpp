#include <iostream>
#include <functional>
#include <cassert>

struct fcnparms {
    int i;
};

class Test {
public:
    using FuncType = std::function<float(const fcnparms&)>;

    static void sim_1(FuncType func, const fcnparms& params) {
        float result = func(params);
        std::cout << "sim_1 result: " << result << std::endl;
    }

    static void sim_2(FuncType func, const fcnparms& params) {
        float result = func(params);
        std::cout << "sim_2 result: " << result << std::endl;
    }
};

int main() {
    Test::FuncType exampleFunc = [](const fcnparms& p) -> float {
        return p.i * 2.0f;
    };

    fcnparms params{10};
    Test::sim_1(exampleFunc, params);
    Test::sim_2(exampleFunc, params);

    return 0;
}