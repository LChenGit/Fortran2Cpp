#include <iostream>
#include <iomanip>
#include <string>

void printTimestamp(int y, int m, int d, int h, int n, int s) {
    std::string month[] = {
        "January  ", "February ", "March    ", "April    ",
        "May      ", "June     ", "July     ", "August   ",
        "September", "October  ", "November ", "December "
    };
    
    std::string ampm = (h >= 12) ? "PM" : "AM";
    if (h == 12 && n == 0 && s == 0) {
        ampm = "Noon";
    } else if (h == 0 && n == 0 && s == 0) {
        ampm = "Midnight";
    } else if (h == 0 || h > 12) {
        h = (h % 12 == 0) ? 12 : h % 12;
    }

    std::cout << std::setfill('0') << std::setw(2) << d << " "
              << month[m - 1] << " "
              << y << "  "
              << std::setw(2) << h << ":"
              << std::setw(2) << n << ":"
              << std::setw(2) << s << " "
              << ampm << std::endl;
}

int main() {
    printTimestamp(2023, 4, 15, 12, 0, 0); // Test Noon
    printTimestamp(2023, 4, 16, 0, 0, 0);  // Test Midnight
    printTimestamp(2023, 4, 15, 15, 45, 30); // Test 3:15 PM

    return 0;
}