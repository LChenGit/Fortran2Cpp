#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

double digit(const std::string& string, int istart) {
    int i0 = static_cast<int>('0');
    int i9 = static_cast<int>('9');
    int ineg = static_cast<int>('-');
    int ipos = static_cast<int>('+');
    int idot = static_cast<int>('.');
    int ispc = static_cast<int>(' ');
    double c1 = 0.0;
    double c2 = 0.0;
    bool sign = true;
    int l = string.length();
    int idig = 0;
    int i, n, j;
    bool decimalPointReached = false;
    for (i = istart; i < l; ++i) {
        n = static_cast<int>(string[i]);
        if (n >= i0 && n <= i9) {
            idig += 1;
            if (!decimalPointReached) {
                c1 = c1 * 10.0 + (n - i0);
            } else {
                c2 = c2 * 10.0 + (n - i0);
            }
        } else if ((n == ineg || n == ipos || n == ispc) && idig == 0) {
            if (n == ineg) sign = false;
        } else if (n == idot) {
            decimalPointReached = true;
        } else {
            break;
        }
    }
    if (decimalPointReached && c2 > 0.0) {
        while (c2 >= 1.0) {
            c2 /= 10.0;
        }
    }
    double result = c1 + c2;
    if (!sign) result = -result;
    return result;
}