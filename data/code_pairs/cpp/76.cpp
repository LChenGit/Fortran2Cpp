#ifndef BAR_HPP
#define BAR_HPP

// Definition of an abstract base class 'bar_type'
class bar_type {
public:
    virtual ~bar_type() = default; // Virtual destructor for polymorphic deletion
    virtual void test_method() const = 0; // Pure virtual function
};

#endif // BAR_HPP