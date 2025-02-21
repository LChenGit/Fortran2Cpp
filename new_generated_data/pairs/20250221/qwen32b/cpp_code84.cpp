#include <iostream>
#include <string>

using namespace std;

// Example function to add two integers
int add_numbers(int a, int b) {
    return a + b;
}

// Example function to display a message
void display_message(const string& message) {
    cout << message << endl;
}

int main() {
    // Declare variables
    int result;

    // Example function call
    result = add_numbers(5, 3);
    cout << "Result of addition: " << result << endl;

    // Example subroutine call
    display_message("Hello, C++!");

    return 0;
}