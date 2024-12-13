#include <string>
#include <vector>
#include <cmath>

namespace types {

class person {
public:
    std::string forename;
    int age;
};

class kids {
public:
    person oldest_child;
    std::vector<person> other_kids;
};

class NUMERIC_SEQ {
public:
    int int_val;
    float real_val;
    bool log_val;
};

class POINT {
public:
    float x, y;

    float LENGTH() const {
        return std::sqrt(x*x + y*y);
    }
};

} // namespace types