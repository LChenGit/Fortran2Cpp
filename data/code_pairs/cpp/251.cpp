#include <iostream>
#include <vector>

class NeutrinoInfoStorage {
private:
    struct NeutrinoInfo {
        bool flagOK = false;
        float value = 0.0f;
        float value_rec = 0.0f;
        float value_rec_2 = 0.0f;
    };

    std::vector<NeutrinoInfo> EXP_nuInfo;

public:
    void neutrinoInfoStorage_Init(int NumInitialEvents) {
        EXP_nuInfo.clear();
        EXP_nuInfo.resize(NumInitialEvents);
    }

    void neutrinoInfoStorage_Clear() {
        EXP_nuInfo.clear();
    }

    size_t size() const {
        return EXP_nuInfo.size();
    }
};

int main() {
    NeutrinoInfoStorage storage;

    storage.neutrinoInfoStorage_Init(5);
    if (storage.size() == 5) {
        std::cout << "Test PASS: NeutrinoInfoStorage initialized with 5 events." << std::endl;
    } else {
        std::cout << "Test FAIL: NeutrinoInfoStorage not correctly initialized." << std::endl;
    }

    storage.neutrinoInfoStorage_Clear();
    if (storage.size() == 0) {
        std::cout << "Test PASS: NeutrinoInfoStorage cleared correctly." << std::endl;
    } else {
        std::cout << "Test FAIL: NeutrinoInfoStorage not cleared correctly." << std::endl;
    }

    return 0;
}