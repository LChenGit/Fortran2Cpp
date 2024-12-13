#include <cmath>  // for log and pow functions
#include <iostream>

void get_npw2(int npts, double signnpw2, int &npw2) {
    int npw2_exp = static_cast<int>(std::log(static_cast<double>(npts)) / std::log(2.0));
    if (signnpw2 < 0.0) {
        npw2 = static_cast<int>(std::pow(2.0, npw2_exp));
    } else {
        int npw2_temp = static_cast<int>(std::pow(2.0, npw2_exp));
        if (npw2_temp == npts) {
            npw2 = npts;
        } else {
            npw2 = static_cast<int>(std::pow(2.0, npw2_exp + 1));
        }
    }
}

int main() {
    int npts;
    double signnpw2;
    int npw2;

    // Test 1
    npts = 10;
    signnpw2 = 1.0;
    get_npw2(npts, signnpw2, npw2);
    std::cout << "Test 1 - npw2: " << npw2 << std::endl;

    // Test 2
    npts = 10;
    signnpw2 = -1.0;
    get_npw2(npts, signnpw2, npw2);
    std::cout << "Test 2 - npw2: " << npw2 << std::endl;

    // Test 3
    npts = 16;
    signnpw2 = 1.0;
    get_npw2(npts, signnpw2, npw2);
    std::cout << "Test 3 - npw2: " << npw2 << std::endl;

    // Test 4
    npts = 16;
    signnpw2 = -1.0;
    get_npw2(npts, signnpw2, npw2);
    std::cout << "Test 4 - npw2: " << npw2 << std::endl;

    return 0;
}