#include <vector>
#include <string>
#include <iostream>

namespace LOCALD_mod {

void LOCALD(int X, int Y, std::vector<int>& SEQ, int& NSEQ, const std::string& TEXT, const std::string& MODE) {
    SEQ.clear();
    for (int i = X; i <= Y; ++i) {
        SEQ.push_back(i);
    }
    NSEQ = static_cast<int>(SEQ.size());
}

} // namespace LOCALD_mod

int main() {
    int X = 1, Y = 5, NSEQ;
    std::vector<int> SEQ;
    std::string TEXT = "example", MODE = "test";

    LOCALD_mod::LOCALD(X, Y, SEQ, NSEQ, TEXT, MODE);

    std::cout << "NSEQ: " << NSEQ << std::endl;
    std::cout << "SEQ: ";
    for (int num : SEQ) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}