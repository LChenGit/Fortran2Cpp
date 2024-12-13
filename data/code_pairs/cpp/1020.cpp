#include <iostream>
#include <string>

std::string extractSubstring(const std::string& input) {
    return input.substr(1, 5); // Extract characters 2 to 6
}

int main() {
    std::string testString = "A123456789";
    std::string substring = extractSubstring(testString);
    
    std::cout << "Substring: '" << substring << "'" << std::endl;
    
    return 0;
}