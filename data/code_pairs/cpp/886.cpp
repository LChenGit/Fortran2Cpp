#include <memory>
#include <vector>
#include <typeinfo>

class T {
public:
    virtual ~T() = default;
};

class T2 : public T {
};