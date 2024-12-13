#include <iostream>
using namespace std;

class m1 {
public:
    void bar() {
        cout << "bar called" << endl;
    }

    void bar_none(int i) {
        cout << "bar_none called with i = " << i << endl;
    }

    void none_bar(float x) {
        cout << "none_bar called with x = " << x << endl;
    }
};

int main() {
    m1 instance;
    instance.bar();
    instance.bar_none(10);
    instance.none_bar(5.5f);

    cout << "All C++ tests passed." << endl;

    return 0;
}