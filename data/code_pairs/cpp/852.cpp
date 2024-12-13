#include <vector>
#include <algorithm>
#include <iostream>

class Test1 {
public:
    static void valid(int& lhs, const std::vector<int>& rhs) {
        lhs = rhs[0];
    }

    static void valid2(std::vector<int>& lhs, const std::vector<std::vector<int>>& rhs) {
        for (size_t i = 0; i < lhs.size(); ++i) {
            lhs[i] = rhs[i][0];
        }
    }
};

class Test2 {
public:
    static void invalid(int& lhs, int rhs) {
        lhs = rhs;
    }
};

class Test3 {
public:
    static void invalid2(std::vector<int>& lhs, int rhs) {
        std::fill(lhs.begin(), lhs.end(), rhs);
    }
};

class Test4 {
public:
    static void invalid3(std::vector<int>& lhs, const std::vector<int>& rhs) {
        lhs = rhs;
    }
};