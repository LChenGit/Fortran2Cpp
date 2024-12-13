#include <iostream>
#include <cmath>
#include <cstdint>

bool concealed_sqr(int64_t tmp) {
    bool result = tmp % 10 == 0;
    int64_t i = tmp / 100;
    int64_t a = 9;

    while (i > 0 && result) {
        result = (i % 10 == a);
        i = i / 100;
        a--;
    }

    return result;
}

int main() {
    int64_t MIN_RES = 1020304050607080900;
    int64_t i = static_cast<int64_t>(std::floor(std::sqrt(static_cast<double>(MIN_RES))));

    while(true) {
        if(concealed_sqr(i*i)) {
            break;
        }
        i++;
    }

    std::cout << "The number is: " << i << std::endl;

    return 0;
}