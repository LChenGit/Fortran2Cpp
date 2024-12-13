#include <vector>
#include <string>

// Function prototypes
void foo(std::vector<int>& a);
void bar(std::vector<std::string>& c);

int main() {
    // Main function is not the focus here, as functionality is tested via unit tests
    return 0;
}

void foo(std::vector<int>& a) {
    for (auto& element : a) {
        element += 1; // Increment each element by 1
    }
}

void bar(std::vector<std::string>& c) {
    for (auto& str : c) {
        str = "Modified"; // Modify each string to "Modified"
    }
}