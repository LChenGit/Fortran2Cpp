#include <iostream>
using namespace std;

int main() {
    int nl = 5;
    int nmg = 2;
    double cl[10];
    
    // Initialize all elements to 1.0
    for (int i = 0; i < 10; ++i) {
        cl[i] = 1.0;
    }
    
    if (nl > 4 && nmg > 1) {
        cout << "Inside the condition" << endl;
        nl -= 1;
        cout << "Modified NL value: " << nl << endl;
        cl[nl - 1] /= cl[nl + 1];
    }
    
    // Print final values
    cout << "Final CL values:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << cl[i] << " ";
    }
    cout << endl;
    cout << "Final NL value: " << nl << endl;
    
    return 0;
}