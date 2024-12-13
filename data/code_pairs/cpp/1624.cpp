#include <iostream>
#include <cstdint>
#include <limits>

void maxmin(const int16_t* data, int npix, int nlin, int inval, int& datmax, int& datmin, int& ierr) {
    bool first = true;
    ierr = 0;
    datmax = std::numeric_limits<int>::min();
    datmin = std::numeric_limits<int>::max();

    for (int line = 0; line < nlin; ++line) {
        for (int pixel = 0; pixel < npix; ++pixel) {
            int datval = data[line * npix + pixel];
            if (datval != inval) {
                if (first) {
                    datmax = datval;
                    datmin = datval;
                    first = false;
                } else {
                    datmax = std::max(datmax, datval);
                    datmin = std::min(datmin, datval);
                }
            }
        }
    }

    if (first) {
        ierr = 1;
        datmin = inval;
        datmax = inval;
    }
}

int main() {
    const int npix = 3, nlin = 3;
    int16_t data[npix * nlin] = {1, 2, 3, -1, 5, 6, 7, 8, 9};
    int datmax, datmin, ierr;

    maxmin(data, npix, nlin, -1, datmax, datmin, ierr);

    std::cout << "Max: " << datmax << std::endl;
    std::cout << "Min: " << datmin << std::endl;
    std::cout << "Error: " << ierr << std::endl;

    return 0;
}