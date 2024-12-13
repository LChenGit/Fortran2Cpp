#include <iostream>

struct Sub {
    int i = 0;
};

struct T {
    Sub sub;
};

union TU {
    int i;
    float r;
};

void sub0(T& u) {
    u.sub.i = 0;
}

void sub1() {
    T u;
    sub0(u);
}

void sub2(TU& u) {
    u.r = 1.0f;
}