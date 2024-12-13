#include <iostream>
#include <cmath> // For fabs function

class eapVarApp {
public:
    static float f(float x) {
        float j, k, l;
        j = x;
        k = g(j * j);
        l = j * g(j * j * j);
        return k;
    }
    
    static float g(float x) {
        return x;
    }
    
    static float h(float x) {
        return f(x);
    }
};