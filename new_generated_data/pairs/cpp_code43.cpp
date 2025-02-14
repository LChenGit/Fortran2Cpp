#include <string>
#include <cassert>
#include <cstdlib>

void test_index() {
    std::string x = "12345";
    size_t pos = x.find("blablabl");
    
    if (pos != std::string::npos) {
        assert(false && "Test failed: substring should not be found.");
    }
}

int main() {
    test_index();
    return 0;
}