#include <string>
#include <vector>

std::string copyFirstElement(const std::vector<std::string>& wbuf2) {
    std::string wbuf1(2, ' ');
    if (!wbuf2.empty()) {
        wbuf1 = wbuf2[0].substr(0, 2);
    }
    return wbuf1;
}