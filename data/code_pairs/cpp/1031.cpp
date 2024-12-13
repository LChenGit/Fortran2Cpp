// othermod.h
#ifndef OTHERMOD_H
#define OTHERMOD_H

namespace othermod {
    void othersub() {
        // Placeholder for othersub functionality
    }
}

#endif // OTHERMOD_H

// testmod.h
#ifndef TESTMOD_H
#define TESTMOD_H

#include "othermod.h"
#include <iostream>

namespace testmod {

    class t1 {
    public:
        void proc1() {
            std::cout << "proc1 called" << std::endl;
        }

        float proc2(float x) {
            float result = x / 2.0f;
            std::cout << "proc2 called with x = " << x << " result is " << result << std::endl;
            return result;
        }
    };

    class t2 {
    public:
        int proc3() {
            std::cout << "proc3 called, result is 42" << std::endl;
            return 42;
        }
    };

};

#endif // TESTMOD_H

// main.cpp
#include "testmod.h"

int main() {
    testmod::t1 obj1;
    testmod::t2 obj2;
    
    obj1.proc1(); // Testing proc1
    float result2 = obj1.proc2(4.0f); // Testing proc2
    std::cout << "Test proc2 result: " << result2 << std::endl;
    
    int result3 = obj2.proc3(); // Testing proc3
    std::cout << "Test proc3 result: " << result3 << std::endl;

    return 0;
}