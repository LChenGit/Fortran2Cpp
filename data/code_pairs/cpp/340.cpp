#include <iostream>

class M1 {
public:
    void bar() {
        std::cout << "In bar" << std::endl;
    }

    void bar_none(int i) {
        std::cout << "In bar_none with i = " << i << std::endl;
    }

    void none_bar(float x) {
        std::cout << "In none_bar with x = " << x << std::endl;
    }
};