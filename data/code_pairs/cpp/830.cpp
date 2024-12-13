#include <vector>

int intCnt(int target, const std::vector<int>& list) {
    int count = 0;
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == target) {
            count++;
        }
    }
    return count;
}