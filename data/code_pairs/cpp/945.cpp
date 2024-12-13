#include <iostream>
#include <string>
using namespace std;

void check_output() {
    cout << "check" << endl;
}

int main() {
    char f[6] = "(a)"; // Note: 'f' is declared but not used in this example
    check_output();
    return 0;
}