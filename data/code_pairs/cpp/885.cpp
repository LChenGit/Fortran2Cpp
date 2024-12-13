#include <iostream>

namespace Members {

    class HasMembers {
    public:
        int kind_member;
        int len_member;
        int member;

        HasMembers(int kind, int len, int mem) : kind_member(kind), len_member(len), member(mem) {}

        void MyMethod() const {
            std::cout << "Member value: " << member << std::endl;
        }
    };

    void MySubroutine(int arg) {
        std::cout << "MySubroutine called with arg = " << arg << std::endl;
    }

}