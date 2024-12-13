#include <iostream>
#include <vector>
#include <string>

void ufaceload(
    const std::vector<std::vector<double>>& co,
    const std::vector<int>& ipkon,
    const std::vector<int>& kon,
    const std::vector<std::string>& lakon,
    int nboun,
    const std::vector<int>& nodeboun,
    std::vector<std::vector<int>>& nelemload,
    const std::vector<std::string>& sideload,
    int nload,
    int ne,
    int nk
) {
    // For testing: Increment each element in nelemload by 1
    for (auto& row : nelemload) {
        for (auto& elem : row) {
            ++elem;
        }
    }
}

int main() {
    std::vector<std::vector<double>> co = {{0}};
    std::vector<int> ipkon = {0}, kon = {0}, nodeboun = {0};
    std::vector<std::string> lakon = {""}, sideload = {""};
    std::vector<std::vector<int>> nelemload = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
    int nboun = 1, nload = 5, ne = 1, nk = 1;
    
    ufaceload(co, ipkon, kon, lakon, nboun, nodeboun, nelemload, sideload, nload, ne, nk);
    
    std::cout << "Modified nelemload:" << std::endl;
    for (const auto& row : nelemload) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}