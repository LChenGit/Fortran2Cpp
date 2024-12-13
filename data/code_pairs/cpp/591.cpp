#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cstdlib> // For abort()

struct dt {
    std::string* scalar = nullptr;
    std::vector<std::string> array;
};

int main() {
    dt a;
    std::string scalar_t = "abcd";
    std::array<std::string, 2> array_t = {"abcd", "efgh"};

    a.scalar = new std::string(scalar_t);
    if (*a.scalar != "abcd") std::abort();
    a.array = std::vector<std::string>(array_t.begin(), array_t.end());
    if (a.array[0] != "abcd" || a.array[1] != "efgh") std::abort();
    delete a.scalar;

    a.scalar = &scalar_t;
    if (*a.scalar != "abcd") std::abort();
    // No direct equivalent in C++ for Fortran's pointer to entire array,
    // but the vector's direct assignment above serves a similar purpose.
    if (*a.scalar != "abcd") std::abort();

    return 0;
}