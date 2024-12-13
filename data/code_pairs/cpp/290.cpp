#include <iostream>
#include <vector>
#include <string>

class ByteType {
    char singleByte;
public:
    ByteType() : singleByte(0) {}
    ByteType(char c) : singleByte(c) {}
    char getByte() const { return singleByte; }
};

std::vector<ByteType> StringToBytes(const std::string &v) {
    std::vector<ByteType> bytes;
    for (char c : v) {
        bytes.push_back(ByteType(c));
    }
    return bytes;
}

std::string BytesToString(const std::vector<ByteType> &bytes) {
    std::string str;
    for (const ByteType &b : bytes) {
        str += b.getByte();
    }
    return str;
}

int main() {
    std::string str = "Hello, world!";
    auto bytes = StringToBytes(str);
    std::string convertedStr = BytesToString(bytes);

    if (convertedStr != str) {
        std::cerr << "Conversion error." << std::endl;
        return 1;
    }

    std::cout << "Conversion successful: " << convertedStr << std::endl;
    return 0;
}