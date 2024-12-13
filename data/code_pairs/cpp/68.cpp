#include <cassert>
#include <iostream>

class Object {
public:
    int i;
    float f;

    Object(int x) : i(x), f(0.0f) {}
    Object(float f) : i(0), f(f) {}
};

class Object_to_rename {
public:
    int i;

    Object_to_rename(int i) : i(i) {}
};

int object_add(const Object& o, int i) {
    return o.i + static_cast<int>(o.f) + i;
}

int object2_val(const Object_to_rename& o) {
    return o.i;
}

int main() {
    Object obj1(10);
    assert(obj1.i == 10 && obj1.f == 0.0f);
    std::cout << "Test 1 Passed" << std::endl;

    Object obj2(5.5f);
    assert(obj2.f == 5.5f && obj2.i == 0);
    std::cout << "Test 2 Passed" << std::endl;

    int sum = object_add(obj1, 5);
    assert(sum == 15);
    std::cout << "Test 3 Passed" << std::endl;

    Object_to_rename obj3(3);
    assert(object2_val(obj3) == 3);
    std::cout << "Test 4 Passed" << std::endl;

    return 0;
}