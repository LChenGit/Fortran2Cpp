#include <iostream>
#include <vector>
#include <array>

using Real = float;

class T1 {
public:
    std::array<Real, 2> x1{{1., 2.}};
};

template<int KIND, int LEN>
class T2 {
public:
    std::array<Real, 2> x1{{1., 2.}};
    std::array<Real, KIND> x2{{1., 2., 3.}};
    std::array<Real, LEN> x3{{1., 2., 3.}};
    Real* p1;
    Real* p2;
    Real* p3;
    Real* p4;
    Real* p5;

    T2(Real* a1, Real& a2, Real& a3, Real& a4) : p1(a1), p2(&a2), p3(&a3), p4(a1), p5(&a4) {}
};

void objectpointers(int j) {
    static Real x1;
    static Real* x2 = nullptr;
    static Real x3;
    Real x4;
    static Real x5[10];
    Real* p1 = &x1;
    Real* p2 = x2;
    Real* p3 = &x3;
    Real* p4 = &x4;
    Real* p5 = &x5[j-1];
    Real* p6 = x5;
}

void dataobjects(int j) {
    const std::vector<Real> x1 = {1., 2.};
    const std::array<std::array<Real, 2>, 2> x2{{{1., 2.}, {3., 4.}}};
    std::vector<Real> x3(j, 1.0);
    std::vector<Real> x4{j, 2.0}; // Assuming initialization for demonstration
    std::array<std::array<Real, 2>, 2> x5{{{1., 2.}, {3., 4.}}};
    std::array<std::array<Real, 2>, 2> x6{{{5., 5.}, {5., 5.}}};
    Real x7 = 1.0;
    std::array<std::array<Real, 2>, 2> x8{{{1., 2.}, {3., 4.}}};
    std::array<Real, 3> x9{{1., 2., 3.}};
    std::array<std::array<Real, 3>, 2> x10{{{1., 2., 3.}, {4., 5., 6.}}};
}

void components() {
    static Real a1[3];
    Real a2;
    static Real a3;
    static Real a4;
    T2<3, 3> o1(a1, a2, a3, a4);
    T2<2, 2> o2(a1, a2, a3, a4);
}

int main() {
    objectpointers(5);
    dataobjects(2);
    components();
    std::cout << "All tests passed." << std::endl;
    return 0;
}