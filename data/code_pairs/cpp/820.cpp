#include <iostream>
#include <complex>
#include <vector>

void csrot(int n, std::complex<float>* cx, int incx, std::complex<float>* cy, int incy, float c, float s) {
    if (n <= 0) return;

    int ix, iy;
    if (incx == 1 && incy == 1) {
        for (int i = 0; i < n; ++i) {
            std::complex<float> ctemp = c * cx[i] + s * cy[i];
            cy[i] = c * cy[i] - s * cx[i];
            cx[i] = ctemp;
        }
    } else {
        ix = 0;
        iy = 0;
        if (incx < 0) ix = (n - 1) * incx;
        if (incy < 0) iy = (n - 1) * incy;
        for (int i = 0; i < n; ++i) {
            std::complex<float> ctemp = c * cx[ix] + s * cy[iy];
            cy[iy] = c * cy[iy] - s * cx[ix];
            cx[ix] = ctemp;
            ix += incx;
            iy += incy;
        }
    }
}

int main() {
    int n = 4;
    std::vector<std::complex<float>> cx(n), cy(n);
    int incx = 1, incy = 1;
    float c = 0.5, s = 0.86602540378f; // roughly sin(60 degrees)

    // Initialize vectors cx and cy with some values
    for (int i = 0; i < n; ++i) {
        cx[i] = std::complex<float>(i+1, i+1);
        cy[i] = std::complex<float>(n-i, -(n-i));
    }

    // Perform the complex rotation
    csrot(n, cx.data(), incx, cy.data(), incy, c, s);

    // Output results for manual verification
    std::cout << "After csrot:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "cx[" << i << "] = " << cx[i] << ", cy[" << i << "] = " << cy[i] << std::endl;
    }

    return 0;
}