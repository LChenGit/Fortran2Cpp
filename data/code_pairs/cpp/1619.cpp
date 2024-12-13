#include <vector>
#include <string>

class StringParser {
public:
    static const int MaxStringLength = 132;
    static const int MaxStringTokens = 100;
    
    std::vector<std::string> StringParts;
    
    StringParser() = default;
    ~StringParser() = default;
};