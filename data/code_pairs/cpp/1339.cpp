// This is a conceptual file. The class T and function abc are actually included in the main C++ code below.
#include <string>
#include <functional>
#include <memory>

class T {
public:
    std::function<std::shared_ptr<std::string>(std::shared_ptr<std::string>)> ptr;
};

std::shared_ptr<std::string> abc(std::shared_ptr<std::string> arg);