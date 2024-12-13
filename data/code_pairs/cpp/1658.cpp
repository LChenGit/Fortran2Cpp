#include <iostream>
#include <string>

int main() {
    std::string str = "abcdefg";
    int array[7];
    for(int i = 0; i < 7; i++) {
        array[i] = i + 1;
    }
    
    std::cout << str.substr(1, 3) << std::endl; // Equivalent to str(2:4) in Fortran
    std::cout << str.substr(0, 3) << std::endl; // Equivalent to str(:3) in Fortran
    std::cout << str.substr(4) << std::endl;    // Equivalent to str(5:) in Fortran
    std::cout << str << std::endl;              // Equivalent to str(:) in Fortran
    return 0;
}