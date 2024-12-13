#include <iostream>
#include <vector>

class COMPUTE_STACEY_CM_BACKWARD__genmod {
public:
    void COMPUTE_STACEY_CM_BACKWARD(const std::vector<float>& inputArray, std::vector<float>& outputArray) {
        size_t size = inputArray.size();
        outputArray.resize(size - 1);
        for (size_t i = 1; i < size; ++i) {
            outputArray[i - 1] = inputArray[i] - inputArray[i - 1];
        }
    }
};