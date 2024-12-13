#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

void timestamp() {
    std::string ampm;
    std::string month[12] = {
        "January  ", "February ", "March    ", "April    ",
        "May      ", "June     ", "July     ", "August   ",
        "September", "October  ", "November ", "December "
    };

    // Get current time
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    int y = now->tm_year + 1900; // tm_year is years since 1900
    int m = now->tm_mon; // tm_mon is months since January [0,11]
    int d = now->tm_mday;
    int h = now->tm_hour;
    int n = now->tm_min;
    int s = now->tm_sec;
    int mm = 0; // Milliseconds are not directly supported in std::tm

    // Handling AM/PM
    if (h < 12) {
        ampm = "AM";
    } else {
        if (h > 12) h -= 12;
        ampm = "PM";
        if (h == 12 && n == 0 && s == 0) {
            ampm = "Noon";
        }
    }

    if (h == 0) h = 12; // Convert 0 hour to 12 for 12-hour format

    // Print formatted timestamp
    std::cout << month[m] << " " << std::setfill('0') << std::setw(2) << d << " " << y << " "
              << std::setw(2) << h << ":" << std::setw(2) << n << ":" << std::setw(2) << s
              << " " << ampm << std::endl;
}

int main() {
    timestamp();
    return 0;
}