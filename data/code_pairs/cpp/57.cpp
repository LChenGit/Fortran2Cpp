// Translated C++ Program
#include <iostream>
#include <string>

int main() {
    std::string fred = "1234567890123456789012345678901234567890";
    std::string trimmedFred = fred.erase(fred.find_last_not_of(" ") + 1); // Trimming is not needed for this input but included for completeness
    int kk = trimmedFred.length();
    std::string cname = trimmedFred.substr(4, kk - 4);
    std::cout << kk << ", " << cname << std::endl;
    return 0;
}