#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

bool is_pal(int targ) {
    std::string targ_str = std::to_string(targ);
    std::string rev_str = targ_str;
    std::reverse(rev_str.begin(), rev_str.end());
    return targ_str == rev_str;
}

int findMaxPalindrome() {
    const int max_val = 999;
    int max_pal = 1;
    for (int i = 1; i <= max_val; ++i) {
        for (int j = i; j <= max_val; ++j) {
            int prod = i * j;
            if (is_pal(prod)) {
                max_pal = std::max(prod, max_pal);
            }
        }
    }
    return max_pal;
}

int main() {
    std::cout << "The largest palindrome made from the product of two 3-digit numbers is: " << findMaxPalindrome() << std::endl;
    return 0;
}