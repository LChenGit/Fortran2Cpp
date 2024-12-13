// DefineModelAK135.cpp
#include <iostream>

class DEFINE_MODEL_AK135__genmod {
public:
    void DEFINE_MODEL_AK135(bool USE_EXTERNAL_CRUSTAL_MODEL) {
        std::cout << "USE_EXTERNAL_CRUSTAL_MODEL is " << std::boolalpha << USE_EXTERNAL_CRUSTAL_MODEL << std::endl;
    }
};

int main() {
    DEFINE_MODEL_AK135__genmod model;
    model.DEFINE_MODEL_AK135(true);
    model.DEFINE_MODEL_AK135(false);
    return 0;
}