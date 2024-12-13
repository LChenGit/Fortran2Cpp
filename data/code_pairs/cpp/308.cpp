#include <memory>

class BaseType {
public:
    virtual std::unique_ptr<BaseType> clone() const = 0;
    virtual ~BaseType() = default; // Ensure proper cleanup
};