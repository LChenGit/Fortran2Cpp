#include <iostream>
#include <vector>
#include <stdexcept>

void imgcpy(const std::vector<std::vector<short>>& ia, int npix, int nlines, std::vector<std::vector<short>>& ib) {
    // Check that the dimensions of ia and ib match npix and nlines
    if (ia.size() != nlines || ib.size() != nlines) {
        throw std::invalid_argument("Dimension mismatch with nlines");
    }

    for (int j = 0; j < nlines; ++j) {
        if (ia[j].size() != npix || ib[j].size() != npix) {
            throw std::invalid_argument("Dimension mismatch with npix");
        }

        for (int i = 0; i < npix; ++i) {
            ib[j][i] = ia[j][i];
        }
    }
}

int main() {
    int npix = 3;
    int nlines = 3;
    std::vector<std::vector<short>> ia = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<short>> ib(nlines, std::vector<short>(npix, 0));

    imgcpy(ia, npix, nlines, ib);

    std::cout << "Copied matrix:" << std::endl;
    for (const auto& line : ib) {
        for (short val : line) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}