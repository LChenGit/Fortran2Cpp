#include <iostream>
#include <typeinfo>
#include <cstdlib>

// Base class t1
class t1 {
public:
    int i;
    virtual ~t1() {} // Ensure polymorphic behavior
};

// Derived class t2
class t2 : public t1 {
public:
    int j;
};

// Helper function to perform type checks similar to SAME_TYPE_AS in Fortran
template<typename T, typename U>
bool same_type_as(T* a, U* b) {
    try {
        return typeid(*a) == typeid(*b);
    } catch (std::bad_typeid&) {
        return false; // Handle case where a or b is null
    }
}