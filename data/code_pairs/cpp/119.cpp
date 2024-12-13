#include <string>

void charln(std::string& text) {
    int klen = text.length();
    while (klen > 0 && text[klen - 1] == ' ') {
        klen--;
    }
    text.resize(klen);
}