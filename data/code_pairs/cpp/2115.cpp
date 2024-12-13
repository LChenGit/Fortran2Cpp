#include <iostream>
using namespace std;

int add(int number1, int number2) {
    return number1 + number2;
}

int main() {
    int number1 = 5, number2 = 7;
    int sum = add(number1, number2);
    cout << "The sum is: " << sum << endl;
    return 0;
}