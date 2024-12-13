#include <iostream>
#include <vector>

int selci_isum(int n, const std::vector<std::vector<int>>& m) {
    int is = 0;
    for (int i = 0; i < n; ++i) {
        is += m[0][i];
    }
    return is;
}

int main() {
    std::vector<std::vector<int>> m = {{1, 2, 3}, {4, 5, 6}};
    int n = 3;

    int result = selci_isum(n, m);
    std::cout << "Test Result: " << result << std::endl;

    return 0;
}