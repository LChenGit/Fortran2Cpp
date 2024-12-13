#include <iostream>
#include <vector>

std::vector<int> w3reddat() {
    const std::vector<int> itd = {1, 24, 1440, 86400, 86400000};
    std::vector<int> itm(4);

    for (size_t i = 0; i < itm.size(); ++i) {
        itm[i] = itd[4] / itd[i];
    }
    return itm;
}

int main() {
    std::vector<int> itm = w3reddat();
    for (int val : itm) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}