#include <iostream>
#include <cassert>

bool notwin(double xw1, double xw2, double x) {
    if (xw1 > xw2) {
        return false;
    } else {
        return x < xw1 || x > xw2;
    }
}