#include <iostream>
using namespace std;

int performLoop() {
    int i, j, k = 0;

    for (i = 1; i <= 100; ++i) {
        k++;
        for (j = 1; j <= 100; ++j) {
            break;
        }
    }
    return k;
}

int main() {
    cout << "Count: " << performLoop() << endl;
    return 0;
}