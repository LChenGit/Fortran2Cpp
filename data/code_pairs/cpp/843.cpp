#include <vector>

void reinit2(std::vector<std::vector<int>>& kontet, std::vector<std::vector<int>>& ifac, std::vector<std::vector<int>>& ieln, int netet_, int newsize,
             std::vector<std::vector<int>>& ifatet, std::vector<std::vector<int>>& itetfa, std::vector<std::vector<int>>& iedg, std::vector<std::vector<int>>& ieled) {
    kontet[3][netet_ - 1] = netet_ + 1;
    for (int i = netet_; i < newsize; ++i) {
        for (int j = 0; j < 3; ++j) {
            kontet[j][i] = 0;
        }
        kontet[3][i] = i + 1;
    }
    kontet[3][newsize - 1] = 0;

    // Initialization routines for ifac, ieln, ifatet, itetfa, iedg, ieled are omitted for brevity
}