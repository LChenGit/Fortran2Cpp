// main.cpp
#include <iostream>
#include <memory>
#include <functional>

using AllocIntegerFunc = std::function<std::unique_ptr<int>()>;

struct ConcreteType {
    AllocIntegerFunc alloc;
};

std::unique_ptr<int> alloc_integer() {
    return std::make_unique<int>(13);
}

int main() {
    auto direct_call = alloc_integer();
    std::cout << *direct_call << std::endl;

    AllocIntegerFunc pp = alloc_integer;
    auto pp_call = pp();
    std::cout << *pp_call << std::endl;

    ConcreteType concrete;
    concrete.alloc = alloc_integer;
    auto concrete_call = concrete.alloc();
    std::cout << *concrete_call << std::endl;

    return 0;
}