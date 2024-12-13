#include <iostream>

int main() {
    int nums[2];
    int &n1 = nums[0]; // Reference to the first element of nums
    int &n2 = nums[1]; // Reference to the second element of nums

    n1 = 12;
    n2 = 34;

    std::cout << nums[0] << " " << nums[1] << std::endl;

    nums[0] = 56;
    nums[1] = 78;

    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;

    return 0;
}