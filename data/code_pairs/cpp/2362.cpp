#include <vector>

class M {
public:
    int a;  // public variable

protected:
    int i;  // protected variable

private:
    int b;  // private variable

public:
    std::vector<int> j;  // equivalent to allocatable, using std::vector for dynamic allocation

    M() : a(0), b(0), i(0) {}  // constructor to initialize variables

    void set_values() {
        a = 5;
        j.push_back(10);
    }

    // In a real application, you might have methods to print or manipulate the class data
};