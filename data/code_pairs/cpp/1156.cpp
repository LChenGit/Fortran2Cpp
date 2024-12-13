#ifndef BAR_H
#define BAR_H

class ESMF_Time {
public:
    int MM; // Assuming MM should be public for operator overloading and other operations.

    // Constructor for initialization
    ESMF_Time(int mm = 0) : MM(mm) {}

    // Operator + overloading for ESMF_Time
    ESMF_Time operator+(const ESMF_Time& rhs) const {
        // Implementing the logic from the Fortran 'add' function
        ESMF_Time result(*this); // Using the current object's state as the base for addition.
        return result;
    }
};

#endif // BAR_H