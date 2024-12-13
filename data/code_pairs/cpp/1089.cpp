#include <iostream>
#include <vector>

void inirea(int len, float rfrom, std::vector<float>& rto) {
    rto.resize(len);
    for(int i = 0; i < len; ++i) {
        rto[i] = rfrom;
    }
}

int main() {
    const int len = 5;
    float rfrom = 2.0f;
    std::vector<float> rto;

    inirea(len, rfrom, rto);

    std::cout << "Testing inirea" << std::endl;
    for(int i = 0; i < len; ++i) {
        std::cout << "rto[" << i << "] = " << rto[i] << std::endl;
        if(rto[i] != rfrom) {
            std::cout << "Test failed." << std::endl;
            return 1; // Return an error code
        }
    }
    std::cout << "All tests passed." << std::endl;
    return 0; // Success
}