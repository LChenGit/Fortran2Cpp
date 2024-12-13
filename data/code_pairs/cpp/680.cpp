#include <vector>

void COUNT_W_LP5(std::vector<int>& result, const std::vector<int>& rext) {
    int totalSize = rext[0] * rext[1] * rext[2] * rext[3];
    result.resize(totalSize, 0);
}