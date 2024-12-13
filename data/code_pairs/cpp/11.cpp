#include <iostream>
#include <vector>
#include <algorithm> // For std::max

void addres(std::vector<int>& jdiag, const std::vector<int>& mht, int& nwk, int& ma, int& mb) {
    jdiag[0] = 1;
    ma = 0;
    mb = 0;
    for (size_t i = 1; i < mht.size(); ++i) {
        ma = std::max(ma, mht[i - 1]);
        mb += mht[i - 1];
        jdiag[i] = jdiag[i - 1] + 1 + mht[i - 1];
    }
    ma += 1;
    mb += mht.back(); // Adding the last element which was missing in the loop.
    mb /= mht.size();
    nwk = jdiag.back();
}