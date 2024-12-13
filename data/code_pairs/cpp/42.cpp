#include <iostream>
#include <iomanip> // For std::setprecision and std::setw
#include <sstream> // For std::stringstream

std::string formatArrays() {
    int nums[] = {12, 34};
    float data[] = {1.2f, 3.4f};
    std::stringstream ss;

    // Format and append the data array to the stringstream
    ss << std::fixed << std::setprecision(1);
    ss << data[0] << " " << data[1] << std::endl;

    // Format and append the nums array to the stringstream
    ss << std::setw(3) << nums[0] << " " << std::setw(3) << nums[1] << std::endl;

    return ss.str();
}

int main() {
    // Output the formatted arrays
    std::cout << formatArrays();
    return 0;
}