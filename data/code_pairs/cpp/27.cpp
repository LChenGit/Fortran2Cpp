#include <iostream>
#include <vector>

void mdu(int ek, int& dmin, std::vector<int>& v, std::vector<int>& l, std::vector<int>& head, std::vector<int>& last, std::vector<int>& next, std::vector<int>& mark) {
    // Example logic for testing
    dmin = 999;
}

int main() {
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> l = {10,9,8,7,6,5,4,3,2,1};
    std::vector<int> head = {1,1,1,1,1,1,1,1,1,1};
    std::vector<int> last = {0,0,0,0,0,0,0,0,0,0};
    std::vector<int> next = {0,0,0,0,0,0,0,0,0,0};
    std::vector<int> mark = {0,0,0,0,0,0,0,0,0,0};
    int ek = 1;
    int dmin = 999;

    mdu(ek, dmin, v, l, head, last, next, mark);

    std::cout << "dmin: " << dmin << std::endl;
    std::cout << "head:";
    for (int h : head) std::cout << " " << h;
    std::cout << std::endl << "last:";
    for (int l : last) std::cout << " " << l;
    std::cout << std::endl << "next:";
    for (int n : next) std::cout << " " << n;
    std::cout << std::endl << "mark:";
    for (int m : mark) std::cout << " " << m;
    std::cout << std::endl;

    return 0;
}