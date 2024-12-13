#include <iostream>

extern "C" { // Ensure C linkage for interoperability with Fortran

struct Container {
    int id; // Example member variable
};

using cFuncPointer = void (*)();

void convert_c_funcpointer(void* cpointer, cFuncPointer& fpointer) {
    fpointer = reinterpret_cast<cFuncPointer>(cpointer);
}

void allocate_Container(void** Container_cptr) {
    *Container_cptr = new Container();
}

void deallocate_Container(void* Container_cptr) {
    Container* Container_ptr = static_cast<Container*>(Container_cptr);
    delete Container_ptr;
}

// Test function to use with convert_c_funcpointer
void testFunction() {
    std::cout << "Function pointer conversion successful." << std::endl;
}

} // extern "C"

int main() {
    // Test convert_c_funcpointer
    cFuncPointer fpointer = nullptr;
    convert_c_funcpointer(reinterpret_cast<void*>(&testFunction), fpointer);
    fpointer(); // Should print a success message

    // Test allocate_Container and deallocate_Container
    void* Container_cptr = nullptr;
    allocate_Container(&Container_cptr);
    std::cout << "Container allocated." << std::endl;

    deallocate_Container(Container_cptr);
    std::cout << "Container deallocated." << std::endl;

    return 0;
}