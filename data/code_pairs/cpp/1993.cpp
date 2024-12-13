#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

int main() {
    std::string buf = "AbCdEf"; // Initialize the string with "AbCdEf".
    int num = -2; // Initialize num with -2.
    
    std::ostringstream formattedNum;
    formattedNum << std::setw(3) << num; // Format num with width 3, resulting in " -2".
    std::string numStr = formattedNum.str(); // Convert the formatted number to a string.
    
    buf.replace(1, 3, numStr); // Replace characters in buf starting at index 1 with numStr.
    
    std::cout << "num = (" << buf << ")" << std::endl; // Output the modified buf.

    return 0;
}