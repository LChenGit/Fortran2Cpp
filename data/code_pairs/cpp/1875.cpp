#include <iostream>

class SEND_SINGLEI__genmod {
public:
    static void SEND_SINGLEI(int SENDBUF, int DEST, int SENDTAG) {
        std::cout << "SENDBUF: " << SENDBUF << std::endl;
        std::cout << "DEST: " << DEST << std::endl;
        std::cout << "SENDTAG: " << SENDTAG << std::endl;
    }
};

void test_SEND_SINGLEI() {
    SEND_SINGLEI__genmod::SEND_SINGLEI(1, 2, 3);
    SEND_SINGLEI__genmod::SEND_SINGLEI(4, 5, 6);
}

int main() {
    test_SEND_SINGLEI();
    return 0;
}