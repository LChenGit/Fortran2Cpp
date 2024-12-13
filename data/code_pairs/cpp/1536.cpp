#include <vector>
#include <iostream>
#include <algorithm> // For std::sort

class Dimensions {
private:
    std::vector<int> dimensionList;
    int indexOfSpecialDimension = 0;

public:
    // Constructor from list of dimensions and a special index
    Dimensions(const std::vector<int>& dimList, int specialIndex)
        : dimensionList(dimList), indexOfSpecialDimension(specialIndex) {}

    void printDimensions() const {
        std::cout << "Dimensions: ";
        for (const auto& dim : dimensionList) {
            std::cout << dim << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int> getOrderedDimensions() const {
        std::vector<int> sortedDimensions = dimensionList;
        std::sort(sortedDimensions.begin(), sortedDimensions.end());
        return sortedDimensions;
    }

    std::vector<int> getUnorderedDimensions() const {
        return dimensionList;
    }

    int getNumberOfDimensions() const {
        return dimensionList.size();
    }

    void deleteDimensions() {
        dimensionList.clear();
        indexOfSpecialDimension = 0;
    }
};