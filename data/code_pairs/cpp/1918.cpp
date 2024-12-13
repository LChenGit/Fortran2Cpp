#include <cstring> // For strncpy

class MyTyp {
public:
    char a[4]; // Extra character for null terminator

    MyTyp() {
        a[0] = 'X'; a[1] = 'Y'; a[2] = 'Z'; a[3] = '\0'; // Correct null termination
    }

    MyTyp(const char* initVal) {
        strncpy(a, initVal, 3);
        a[3] = '\0'; // Ensuring null termination
    }
};