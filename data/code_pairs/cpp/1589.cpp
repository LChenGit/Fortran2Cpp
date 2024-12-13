#include <iostream>
using namespace std;

void TT(float x) {
    cout << "TT called with X = " << x << endl;
}

void DD(void (*F)(float)) {
    F(5.0f); // Passing a test value
}

int main() {
    DD(TT);
    return 0;
}