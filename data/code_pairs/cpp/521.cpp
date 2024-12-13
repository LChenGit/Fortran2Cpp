#include <vector>
#include <iostream>

class modphonon {
public:
    int nbph;
    std::vector<std::vector<double>> vqlwrt;

    modphonon() : nbph(0) {}

    void increase_nbph() {
        ++nbph;
    }

    void resize_vqlwrt(size_t nrows, size_t ncols) {
        vqlwrt.resize(nrows, std::vector<double>(ncols, 0.0));
    }
};