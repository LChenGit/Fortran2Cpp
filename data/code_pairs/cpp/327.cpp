#include <iostream>
#include <vector>
#include <string>
#include <array>

class Foo {
public:
    static void bar(const std::string& arg1, const std::vector<std::string>& arg2, 
                    const std::vector<int>& arg3, int arg4, const std::string& arg5) {
        std::cout << "arg1: " << arg1 << std::endl;
        std::cout << "arg2: ";
        for(const auto& element : arg2) {
            std::cout << element << " ";
        }
        std::cout << std::endl << "arg3: ";
        for(int num : arg3) {
            std::cout << num << " ";
        }
        std::cout << std::endl << "arg4: " << arg4 << std::endl;
        std::cout << "arg5: " << arg5 << std::endl;
    }

    static void foo1(std::vector<std::string>& slist, int i) {
        if(i >= 1 && i <= static_cast<int>(slist.size())) {
            slist[i-1] = "hi=" + std::to_string(i);
        }
    }

    static std::array<std::array<int, 2>, 2> f1(const std::array<std::array<int, 2>, 2>& a) {
        std::array<std::array<int, 2>, 2> result;
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < 2; ++j) {
                result[i][j] = 15 + a[i][j];
            }
        }
        return result;
    }

    static std::array<std::array<int, 2>, 2> e1(const std::array<std::array<int, 2>, 2>& b) {
        std::array<std::array<int, 2>, 2> result;
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < 2; ++j) {
                result[i][j] = 42 + b[i][j];
            }
        }
        return result;
    }
};

int main() {
    // Example usage
    Foo::bar("Test for bar", {"Array element 1", "Array element 2"}, {1, 2, 3, 4}, 4, "abcd");
    
    std::vector<std::string> slist = {"String 1", "String 2", "String 3"};
    Foo::foo1(slist, 2);
    std::cout << "Modified slist(2): " << slist[1] << std::endl;
    
    auto result_f1 = Foo::f1({{{1, 2}, {3, 4}}});
    auto result_e1 = Foo::e1({{{1, 2}, {3, 4}}});
    std::cout << "result_f1:" << std::endl;
    for (const auto& row : result_f1) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "result_e1:" << std::endl;
    for (const auto& row : result_e1) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}