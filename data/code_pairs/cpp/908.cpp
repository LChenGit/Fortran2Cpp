#include <vector>
#include <iostream>

class TObjectList {
    std::vector<int> intList;
    std::vector<double> doubleList;
public:
    void Add(int item) {
        intList.push_back(item);
    }

    void Add(double item) {
        doubleList.push_back(item);
    }

    int getIntElement(size_t index) {
        return intList.at(index);
    }

    double getDoubleElement(size_t index) {
        return doubleList.at(index);
    }
};