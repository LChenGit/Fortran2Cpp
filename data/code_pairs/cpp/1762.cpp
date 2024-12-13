// workshare.h
#include <vector>

class my_mod {
public:
    static int my_func();
};

void workshare(std::vector<float>& aa, std::vector<float>& bb, std::vector<float>& cc,
               std::vector<float>& dd, std::vector<float>& ee, std::vector<float>& ff, int n);

// workshare.cpp
#include "workshare.h"

int my_mod::my_func() {
    return 10;
}

void workshare(std::vector<float>& aa, std::vector<float>& bb, std::vector<float>& cc,
               std::vector<float>& dd, std::vector<float>& ee, std::vector<float>& ff, int n) {
    aa.assign(n, my_mod::my_func());
    cc = dd;
    ee = ff;

    for (int i = 0; i < n; ++i) {
        if (aa[i] != static_cast<float>(my_mod::my_func())) aa[i] = bb[i] * cc[i];
        if (dd[i] < 5) dd[i] = aa[i] * my_mod::my_func();
        if (aa[i] >= static_cast<float>(my_mod::my_func())) cc[i] = aa[i] + my_mod::my_func();
        if (aa[i] <= static_cast<float>(my_mod::my_func())) cc[i] = dd[i] + my_mod::my_func();
    }

    for (int i = 0; i < n && i < my_mod::my_func(); ++i) {
        aa[i] += bb[i];
    }
}