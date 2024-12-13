#include <cassert> // for assert
#include <cstddef> // for std::size_t
#include <iostream>

template<typename T>
const void* f_loc(T* what, std::size_t size)
{
    return static_cast<const void*>(what);
}

int main() {
    int array[] = {1, 2, 3, 4, 5};

    // Getting the address of the first element of the array
    const void* address = f_loc(array, 5);

    // Verifying the address matches the expected address
    assert(address == static_cast<const void*>(&array[0]));

    std::cout << "Test passed: Got the expected address." << std::endl;

    return 0;
}