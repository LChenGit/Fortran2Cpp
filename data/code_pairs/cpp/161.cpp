#include <stdexcept>
#include <string>

namespace mod_alloc {

template<typename T>
void dealloc(T*& x);

template<typename T>
void alloc(T*& x, size_t n) {
    try {
        if (x != nullptr) { // Check if already allocated
            dealloc(x); // Deallocate if necessary
        }
        x = new T[n]; // Allocate new memory
    } catch (const std::bad_alloc& e) { // Catch allocation errors
        // Convert the error to a more descriptive message if necessary
        throw std::runtime_error("Allocation failed: " + std::string(e.what()));
    }
}

template<typename T>
void dealloc(T*& x) {
    if (x != nullptr) { // Check if already allocated
        delete[] x; // Deallocate memory
        x = nullptr; // Avoid dangling pointer
    }
}

} // namespace mod_alloc