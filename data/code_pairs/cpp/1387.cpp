// MyTypes.h
#ifndef MYTYPES_H
#define MYTYPES_H

#include <vector>

class MyTypes {
public:
    static int i_priv; // Static member to hold the private integer.

    static int get_i() {
        return i_priv; // Return the static member variable.
    }

    class MyType {
    public:
        int dummy; // Public integer member.

        MyType(int d = 0) : dummy(d) {} // Constructor with default value.

        int i() const { // Marked as const to indicate it doesn't modify the object.
            return MyTypes::get_i(); // Access the static member of the enclosing class.
        }
    };
};

#endif // MYTYPES_H