#include <array>

class TArray {
private:
    std::array<float, 10> coeff;

public:
    TArray() {
        coeff.fill(0.0f); // Initialize all elements to 0.0
    }

    void setCoeff(const std::array<float, 10>& newCoeff) {
        coeff = newCoeff;
    }

    std::array<float, 10> getCoeff() const {
        return coeff;
    }

    void setCoeffAt(int index, float value) {
        if (index >= 0 && index < coeff.size()) {
            coeff[index] = value;
        }
    }

    float getCoeffAt(int index) const {
        if (index >= 0 && index < coeff.size()) {
            return coeff[index];
        }
        return 0.0f; // Or throw an exception or handle error as needed
    }
};