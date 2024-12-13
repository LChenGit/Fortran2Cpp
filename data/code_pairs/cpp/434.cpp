#include <iostream>
#include <string>

std::string checkValue(int a) {
    if (a == 10) {
        a = a + 1; // Since 'a' is a copy, this change doesn't affect the output directly but reflects the logic of the original Fortran code.
        return "a incremented";
    } else if (a == 20) {
        return "Value of a is 20";
    } else if (a == 30) {
        return "Value of a is 30";
    } else {
        return "None of the values is matching";
    }
}

int main() {
    int a = 100;
    std::cout << "The checkValue function called with 'a' as " << a << ": " << checkValue(a) << std::endl;
    return 0;
}