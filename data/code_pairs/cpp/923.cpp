#include <cstdint> // For std::int32_t
#include <iostream>

namespace m {

struct bindc_t {
    std::int32_t x;
};

class sequence_t {
public:
    virtual ~sequence_t() {}
    std::int32_t x;
};

class abst_t {
public:
    abst_t() = default;
    virtual ~abst_t() {}
    int x = 0;
};

class concrete_t : public abst_t {
public:
    int y = 1;
};

class myt {
public:
    abst_t* comp; // Pointer to abstract class because we cannot instantiate abst_t directly.
};

class again_abst_t : public concrete_t {
public:
    again_abst_t() = default;
    virtual ~again_abst_t() {}
    int z = 2;
};

} // namespace m

int main() {
    m::concrete_t concObj;
    std::cout << concObj.x << " " << concObj.y << std::endl;
    return 0;
}