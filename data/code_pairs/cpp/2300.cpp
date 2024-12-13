#include <iostream>
#include <string>
#include <vector>

void INSERT(std::vector<int>& ILIST, std::vector<double>& DLIST, std::vector<std::string>& SLIST) {
    // The function does nothing and simply returns
    return;
}

int main() {
    std::vector<int> ILIST = {1, 2, 3};
    std::vector<double> DLIST = {1.1, 2.2, 3.3};
    std::vector<std::string> SLIST = {"one", "two", "three"};

    // Call the INSERT function
    INSERT(ILIST, DLIST, SLIST);

    std::cout << "INSERT function executed successfully." << std::endl;

    return 0;
}