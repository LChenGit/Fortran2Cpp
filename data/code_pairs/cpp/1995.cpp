#include <iostream>
#include <vector>

template<typename T>
void inner(const T& dummy) {
    if constexpr (std::is_same_v<T, std::vector<int>>) {
        std::cout << "Processing a container" << std::endl;
        for (const auto& element : dummy) {
            std::cout << "Element: " << element << std::endl;
        }
    } else if constexpr (std::is_same_v<T, std::vector<double>>) {
        std::cout << "Processing a container" << std::endl;
        for (const auto& element : dummy) {
            std::cout << "Element: " << element << std::endl;
        }
    } else {
        std::cout << "Processing a single value: " << dummy << std::endl;
    }
}

template<typename Container1, typename Container2, typename T>
void s(const Container1& arg1, const Container2& arg2, const T& arg3) {
    inner(arg1);
    inner(arg2);
    inner(arg3);
}

int main() {
    std::vector<int> vecInt = {1, 2, 3};
    std::vector<double> vecDouble = {1.1, 2.2, 3.3};
    int singleInt = 10;

    s(vecInt, vecDouble, singleInt);

    return 0;
}