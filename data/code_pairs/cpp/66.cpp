#include <vector>
#include <string>

void move(
    std::vector<float>& p1, std::vector<float>& p2,
    std::vector<float>& wl1, std::vector<float>& wl2,
    std::vector<double>& disp1, std::vector<double>& disp2,
    int& np1, int& np2,
    std::string& ob1, std::string& ob2,
    std::string& fn1, std::string& fn2,
    std::string& xf1, std::string& xf2,
    std::string& xa1, std::string& xa2,
    std::string& type1, std::string& type2
) {
    const int array_size = 131072;
    const int disp_size = 9;

    xa2 = xa1;
    np2 = np1;
    ob2 = ob1;
    fn2 = fn1;
    xf2 = xf1;
    type2 = type1;

    std::memcpy(p2.data(), p1.data(), array_size * sizeof(float));
    std::memcpy(wl2.data(), wl1.data(), array_size * sizeof(float));
    std::memcpy(disp2.data(), disp1.data(), disp_size * sizeof(double));
}